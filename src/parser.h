#ifndef PARSER_H
#define PARSER_H

#include "dom.h"
#include "node.h"
#include <string>
#include <memory>

class Parser
{
	public:
	Parser() = delete;
	Parser(std::unique_ptr<std::vector<std::string>> lines, std::shared_ptr<Dom> domtree);
	~Parser() = default;

	void parse();

	private:
	std::vector<std::string> lines_;
	std::shared_ptr<Dom> dom_tree;
};

#endif // PARSER_H
