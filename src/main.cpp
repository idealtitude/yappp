#include "args.h"
#include "futil.h"
#include "parser.h"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using std::cout;

const std::string app_name{"yap++"};
const std::string app_version{"0.1.0"};
const std::string help_msg{R"(Usage: yap++ [OPTIONS]... [TERMS]...

Options:
  -i, --interactive    Start interactive session
  -o, --output         Name of the output file
  -w, --watch          Automatically retranspile each time changes happen on the input file
  -h, --help           Display this help message and exit
  -v, --version        Display the current app version)"};

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
		else if (std::string_view(argv[1]) == "-i" or std::string_view(argv[1]) == "--interactive")
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
		std::vector<std::string_view> arguments(argv + 1, argv + argc);
		Args args(arguments);

		if (!args.status_)
		{
			std::cerr << "\033[31mError:\033[0m Could not parse arguments... Do:  " << app_name << " --help to see how to form the query.\n";

			return 1;
		}

		std::unique_ptr<std::map<std::string, std::variant<std::string, bool>>> app_args = args.ret_appargs();

		std::variant<std::string, bool> input = (*app_args)["input"];

		cout << std::get<std::string>(input) << '\n';

		// Futil file_in{fs::path(std::get<std::string>(*app_args["input"]))};

		// if (!file_in.status_)
		// {
		// 	cout << file_in.errormsg_;
		// 	return 1;
		// }

		// file_in.get_file_content();

		// if (!file_in.status_)
		// {
		// 	cout << file_in.errormsg_;
		// 	return 1;
		// }

		// Dom dom;
		// std::shared_ptr<Dom> domtree = std::make_shared<Dom>(dom);
		// Parser parser(file_in.content_, domtree);
	}

	return 0;
}
