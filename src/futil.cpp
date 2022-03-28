#include "futil.h"

Futil::Futil(const fs::path& file)
	: status_(false), file_(file)
{
	do_checks();
}

bool Futil::file_exists()
{
	if (fs::exists(file_))
	{
		return true;
	}

	return false;
}

bool Futil::is_file()
{
	if (fs::is_regular_file(file_))
	{
		return true;
	}

	return false;
}

bool Futil::is_readable()
{
	if (
		(fs::status(file_).permissions() & fs::perms::owner_read) != fs::perms::none
	)
	{
		return true;
	}

	return false;
}

bool Futil::is_writable()
{
	if (
		(fs::status(file_).permissions() & fs::perms::owner_write) != fs::perms::none
	)
	{
		return true;
	}

	return false;
}

void Futil::do_checks()
{

	if (!file_exists())
	{
		errormsg_ =  "\033[31mError:\033[0m The file " + std::string(file_) + " does not exist; check its path\n";
		status_ = false;
	}
	else if (!is_file())
	{
		errormsg_ = "\033[31mError:\033[0m The file " + std::string(file_) + " is not a regular file and can't be opened\n";
		status_ = false;
	}
	else
	{
		status_ = true;
	}

}

void Futil::get_file_content()
{
	if (!is_readable())
	{
		errormsg_ = "\033[31mError:\033[0m The file " + std::string(file_) + " is not readable; check its permissions\n";
		status_ = false;
	}
	else
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
}

void Futil::set_file_content()
{
	if (!is_writable())
	{
		errormsg_ = "\033[31mError:\033[0m The file " + std::string(file_) + " is not writable; check its permissions\n";
		status_ = false;
	}
	else
	{
		std::fstream file_ofs;
		file_ofs.open(file_, std::fstream::out);

		if (!file_ofs.is_open())
		{
			errormsg_ = "\033[31mError:\033[0m Can not open " + std::string(file_) + '\n';
			status_ = false;
		}

		for (const auto& line: content_)
		{
			file_ofs << line << '\n';
		}

		file_ofs.close();
		status_ = true;
	}
}
