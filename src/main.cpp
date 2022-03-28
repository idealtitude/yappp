#include "args.h"
#include "futil.h"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using std::cout;

const std::string app_name{"qn"};
const std::string app_version{"0.2.0"};
const std::string help_msg{R"(Usage: qn [OPTIONS]... [TERMS]...

Options:
  -h, --help       Display this help message and exit
  -v, --version    Display the current app version)"};

void print_help()
{
	cout << help_msg << '\n';
}

void print_version()
{
	cout << app_name << ' ' << app_version << '\n';
}

void interactive_mode()
{
	cout << "Not yet implemented!\n";
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		interactive_mode();
	}
	else if (argc == 2)
	{
		if (std::string_view(argv[1]) == "-h" or std::string_view(argv[1]) == "--help")
		{
			print_help();
		}
		else if (std::string_view(argv[1]) == "-v" or std::string_view(argv[1]) == "--version")
		{
			print_version();
		}
		else if (std::string_view(argv[1]) == "-i" or std::string_view(argv[1]) == "--inter")
		{
			interactive_mode();
		}
		else
		{
			std::cerr << "\033[31mError:\033[0m unknown argument... " << argv[1] << ". Do:  " << app_name << " --help to see how to form the query.\n";
			return 1;
		}
	}
	else
	{
		std::unique_ptr<std::vector<std::string_view> arguments(argv + 1, argv + argc);
		Args args(arguments);

		if (!args.status_[1] and !args.status_[2])
		{
			std::cerr << "\033[31mError:\033[0m Could not parse arguments... Do:  " << app_name << " --help to see how to form the query.\n";

			return 1;
		}
	}

	return 0;
}
