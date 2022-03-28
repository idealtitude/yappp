#ifndef ARGS_H
#define ARGS_H

#include <vector>
#include <string_view>
#include <memory>

using Svec = std::vector<std::string_view>;

class Args
{
	public:
	Args() = delete;
	Args(const Svec& args);
	~Args() = default;

	bool status_;

	private:
	Svec args_;

	void parse_args();
};

#endif // ARGS_H
