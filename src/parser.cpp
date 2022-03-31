#include "parser.h"

Parser::Parser(const std::vector<std::string>& lines, std::shared_ptr<Dom> domtree):
	lines_(lines),
	dom_tree(domtree)
{}
