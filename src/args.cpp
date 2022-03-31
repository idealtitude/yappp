#include "args.h"

Args::Args(const Svec& args):
	status_{false},
	args_(args)
{
	parse_args();
}

void Args::parse_args()
{
	appargs_["watch"] = false;
	appargs_["output"] = "default";

	bool look_for_output{false};

	for (const auto& arg: args_)
	{
		if ((arg == "-o" or arg == "--output") and !look_for_output)
		{
			look_for_output = true;
			continue;
		}

		if (look_for_output)
		{
			appargs_["output"] = std::string(arg);
			look_for_output = false;
			continue;
		}

		if (arg == "-w" or arg == "--watch")
		{
			appargs_["watch"] = true;
			continue;
		}

		if (!look_for_output)
		{
			appargs_["input"] = std::string(arg);
			status_ = true;
			continue;
		}
	}
}

std::unique_ptr<Appargs> Args::ret_appargs()
{
	return std::make_unique<Appargs>(appargs_);
}
