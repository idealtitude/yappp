#ifndef TOKENS_H
#define TOKENS_H

#include <string>
#include <regex>
#include <map>
#include <optional>

std::map<std::string, std::string> tokens_{
	{std::string("t_empty"), std::string("^ *$")},
	{std::string("t_comment"), std::string("^--- *.*$")},
	{std::string("t_indent"), std::string(R"(^\t+)")},
	{std::string("t_attributes"), std::string(R"((#|\.|[a-z0-9-]+)`(.*?)`)")}
};

std::optional<std::smatch> t_match(const std::string& subject, const std::string& token);

#endif // TOKENS_H
