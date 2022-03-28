#include "args.h"

Args::Args(const Svec& args)
	: status_{false}, args_(args)
{
	parse_args();
}

void Args::parse_args()
{
	for (const auto& arg: args_)
	{
		if (arg == "-e" or arg == "--exact")
		{
			status_ = true;
			continue;
		}
	}
}
