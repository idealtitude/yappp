#ifndef TOKENS_H
#define TOKENS_H

#include <string>
#include <regex>
#include <map>

const std::map<std::string, std::regex> tokens_{
	{std::string("t_empty"), std::regex("^ *$")},
	{std::string("t_comment"), std::regex("^--- *.*$")},
	{std::string("t_indent"), std::regex("^\\t+")},
	{std::string("t_attributes"), std::regex(R"((#|\.|[a-z0-9-]+)`(.*?)`)")}
};

#endif // TOKENS_H
