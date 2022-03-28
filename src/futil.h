#ifndef FUTIL_H
#define FUTIL_H

#include <filesystem>
//#include <memory>
#include <string>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

class Futil
{
	public:
	Futil() = delete;
	Futil(const fs::path& file);
	~Futil() = default;

	bool status_;
	std::string errormsg_;
	std::vector<std::string> content_;

	void get_file_content();
	void set_file_content();

	private:
	fs::path file_;

	bool file_exists();
	bool is_file();
	bool is_readable();
	bool is_writable();
	void do_checks();
};

#endif // FUTIL_H
