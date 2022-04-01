#ifndef NODE_H
#define NODE_H

/**
 * variant  :  https://en.cppreference.com/w/cpp/utility/variant
 * optional :  https://en.cppreference.com/w/cpp/utility/optional
 * ref wrapper: https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper
 */

#include <string>
#include <variant>
#include <optional>
#include <vector>
#include <map>
#include <functional>

struct Node
{
	Node() = delete;
	Node(const std::string& tag);
	~Node() = default;

	std::string tag_;
	std::map<std::string, std::string> attributes_;
	bool autoclose_; // Autoclosing tags like <input />
	std::variant<std::string, std::reference_wrapper<Node>> innerHTML_;
	std::optional<std::reference_wrapper<Node>> parent_;
	std::optional<std::vector<std::reference_wrapper<Node>>> children_;
	std::optional<std::reference_wrapper<Node>> sibling_;
	bool state_; // True → open, False → closed
	unsigned int indent_;
};

#endif // NODE_H
