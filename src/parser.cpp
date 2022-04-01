#include "parser.h"

Parser::Parser(std::vector<std::string> lines, std::shared_ptr<Dom> domtree):
	lines_(lines),
	dom_tree(domtree)
{}

void Parser::parse()
{
	unsigned int lineno{0};
	//std::vector<std::string> lines  = *lines_;
	std::unique_ptr<Node> current_node{nullptr};

	for (auto line: lines_)
	{
		++lineno;

		if (line == "!5")
		{
			dom_tree->doctype_ = "<!DOCTYPE html>";
			continue;
		}

		std::optional<std::smatch> check_empty = t_match(line, "t_empty");
		if (check_empty)
		{
			continue;
		}

		std::optional<std::smatch> check_comment = t_match(line, "t_comment");
		if (check_comment)
		{
			continue;
		}

		current_node = create_node(line);
	}
}

std::size_t Parser::get_stack_size() const
{
	return dom_tree->tree_.size();
}

std::unique_ptr<Node> Parser::create_node(std::string line)
{
	unsigned int indent{0};
	bool search_tag{false};

	std::optional<std::smatch> get_indent = t_match(line, "t_indent");
	if (get_indent)
	{
		auto c =  get_indent.value()[1];
		std::cout << "c: " << c << '\n';
		indent = 1;
	}

	if (indent > 0)
	{
		line.erase(0, indent);
	}

	std::optional<std::smatch> get_tag = t_match(line, "t_tag");
	if (get_tag)
	{
		std::string tag = get_tag.value()[1];
		line.erase(0, tag.length());

		if (line.starts_with(' '))
		{
			line.erase(0, 1);
		}

		if (tag.ends_with(':'))
		{
			tag.pop_back();
			search_tag = true;
		}

		dom_tree->tree_.push(Node(tag));
		dom_tree->tree_.top().indent_ = indent;

		while (true)
		{
			if (line.ends_with(';'))
			{
				dom_tree->tree_.top().autoclose_ = true;
				line.pop_back();
				break;
			}

			if (line.ends_with(' '))
			{
				line.pop_back();
			}
			else
			{
				break;
			}

		}

		if (search_tag)
		{
			while (true)
			{
				std::optional<std::smatch> get_attrs = t_match(line, "t_attributes");
				if (get_attrs)
				{
					std::string attr = get_attrs.value()[0];
					std::string key = get_attrs.value()[1];
					std::string val = get_attrs.value()[2];
					dom_tree->tree_.top().attributes_[key] = val;
					line.erase(0, attr.size());
				}
				else
				{
					break;
				}
			}
		}

		if (line.starts_with(' '))
		{
			line.erase(0, 1);
		}

		if (line.starts_with('~'))
		{
			line.erase(0, 1);
			dom_tree->tree_.top().innerHTML_ = line;
			dom_tree->tree_.top().state_ = false;
		}
		else
		{
			dom_tree->tree_.top().state_ = true;
		}

		return std::make_unique<Node>(dom_tree->tree_.top());
	}

	return nullptr;
}
