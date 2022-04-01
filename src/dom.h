#ifndef DOM_H
#define DOM_H

/**
 * Doc stack: https://en.cppreference.com/w/cpp/container/stack/push
 */

#include "node.h"
#include <stack>
//#include <functional>

struct Dom
{
	Dom();
	~Dom() = default;

	std::string doctype_;
	std::stack<Node> tree_;
};

#endif // DOM_H
