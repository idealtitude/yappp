#ifndef FUTIl_H
#define FUTIl_H

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
	bool file_checks[3];
	std::string errormsg_;
	std::vector<std::string> content_;

	void get_file_content();

	private:
	fs::path file_;
	//std::fstream filestream_;

	bool file_exists();
	bool is_file();
	bool is_readable();
	bool do_checks();
};

#endif // FUTIl_H
