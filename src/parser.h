#ifndef PARSER_H
#define PARSER_H

#include "dom.h"
#include "node.h"
#include "tokens.h"
#include <string>
#include <memory>
#include <iostream>

class Parser
{
	public:
	Parser() = delete;
	Parser(std::vector<std::string> lines, std::shared_ptr<Dom> domtree);
	~Parser() = default;

	void parse();
	std::size_t get_stack_size() const;

	private:
	std::vector<std::string> lines_;
	std::shared_ptr<Dom> dom_tree;
	std::unique_ptr<Node> create_node(std::string line);
};

#endif // PARSER_H
