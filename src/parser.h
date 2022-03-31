#ifndef PARSER_H
#define PARSER_H

#include "dom.h"
#include <string>
#include <memory>

class Parser
{
	public:
	Parser() = delete;
	Parser(const std::vector<std::string>& lines, std::shared_ptr<Dom> domtree);
	~Parser() = default;

	private:
	std::vector<std::string> lines_;
	std::shared_ptr<Dom> dom_tree;
};

#endif // PARSER_H
