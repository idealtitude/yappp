#ifndef PARSER_H
#define PARSER_H

#include "dom.h"
#include <string>

class Parser
{
	public:
	Parser() = delete;
	Parser(const std::vector<std::string>& lines);
	~Parser() = default;

	private:
	Dom tree;
};

#endif // PARSER_H
