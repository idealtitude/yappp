#ifndef ARGS_H
#define ARGS_H

#include <vector>
#include <string_view>
#include <map>
#include <variant>
#include <memory>

using Svec = std::vector<std::string_view>;
using Appargs = std::map<std::string, std::variant<std::string, bool>>;

class Args
{
	public:
	Args() = delete;
	Args(const Svec& args);
	~Args() = default;

	bool status_;

	std::unique_ptr<Appargs> ret_appargs();

	private:
	Svec args_;
	Appargs appargs_;

	void parse_args();
};

#endif // ARGS_H
