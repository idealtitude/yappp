#include "node.h"

Node::Node(const std::string& tag):
	tag_{tag},
	attributes_{},
	autoclose_{false},
	innerHTML_{},
	parent_{},
	children_{},
	sibling_{},
	state_{false},
	indent_{0}
{}
