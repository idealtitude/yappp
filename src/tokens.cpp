#include "tokens.h"

std::map<std::string, std::string> tokens_{
	{std::string("t_empty"), std::string("^ *$")},
	{std::string("t_comment"), std::string("^--- *.*$")},
	{std::string("t_indent"), std::string(R"(^\t+)")},
	{std::string("t_attributes"), std::string(R"((#|\.|[a-z0-9-]+)`(.*?)`)")},
	{std::string("t_tag"), std::string(R"(^([a-z0-9-]+:?) )")}
};

std::optional<std::smatch> t_match(const std::string& subject, const std::string& token)
{
	std::regex tok(tokens_[token]);
	std::smatch m;

	if (std::regex_match(subject, m, tok))
	{
		return m;
	}

	return std::nullopt;
}
