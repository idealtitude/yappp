#include "parser.h"

Parser::Parser(std::unique_ptr<std::vector<std::string>> lines, std::shared_ptr<Dom> domtree):
	lines_(lines),
	dom_tree(domtree)
{}

void Parser::parse()
{
	unsigned int lineno{0};
	std::vector<std::string> lines  = lines_.release();

	for (auto line&: lines)
	{
		++lineno;

		if (line == "!5")
		{
			dom_tree->tree_.push(Node("doctypeh5"));
			continue;
		}

		std::optional<std::smatch> check_empty(line, "t_empty");
		if (check_empty)
		{
			continue;
		}

		std::optional<std::smatch> check_comment(line, "t_comment");
		if (check_comment)
		{
			continue;
		}


	}
}
