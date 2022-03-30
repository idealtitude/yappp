#ifndef DOM_H
#define DOM_H

/**
 * Doc stack: https://en.cppreference.com/w/cpp/container/stack/push
 */

#include "node.h"
#include <stack>
#include <functional>

class Dom
{
	public:
	Dom();
	~Dom() = default;

	private:
	std::stack<std::reference_wrapper<Node>> dom_;
};

#endif // DOM_H
