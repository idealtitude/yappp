#include "futil.h"

Futil::Futil(const fs::path& file)
	: status_(false), file_checks{false, false, false}, file_(file)
{
	if (do_checks())
	{
		status_ = true;
	}
}

bool Futil::file_exists()
{
	if (fs::exists(file_))
	{
		file_checks[0] = true;
	}

	return false;
}

bool Futil::is_file()
{
	if (fs::is_regular_file(file_))
	{
		file_checks[1] = true;
	}

	return false;
}

bool Futil::is_readable()
{
	if (
		(fs::status(file_).permissions() & fs::perms::owner_read) != fs::perms::none
	)
	{
		file_checks[2] = true;
	}

	return false;
}

bool Futil::do_checks()
{
	file_exists();
	is_file();
	is_readable();

	if (!file_checks[0])
	{
		errormsg_ =  "\033[31mError:\033[0m The file " + std::string(file_) + " does not exist; check its path\n";
		return false;
	}

	if (!file_checks[1])
	{
		errormsg_ = "\033[31mError:\033[0m The file " + std::string(file_) + " is not a regular file and can't be opened\n";
		return false;
	}

	if (!file_checks[2])
	{
		errormsg_ = "\033[31mError:\033[0m The file " + std::string(file_) + " is not readable; check its permissions\n";
		return false;
	}

	return true;
}

void Futil::get_file_content()
{
	std::fstream file_ifs;
	file_ifs.open(file_, std::fstream::in);

	if (!file_ifs.is_open())
	{
		errormsg_ = "\033[31mError:\033[0m Can not open " + std::string(file_) + '\n';
		status_ = false;
	}

	std::string line;
	while(std::getline(file_ifs, line))
	{
		content_.push_back(line);
	}

	file_ifs.close();
	status_ = true;
}
