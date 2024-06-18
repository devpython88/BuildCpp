#include "essentials/file_io.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

const std::string VERSION = "v1.0";

int main(int argc, char const *argv[])
{
	if (argc == 0){
		return 0;
	}

	std::string file = argv[1];

	if (file == "--version"){
		std::cout << "BuildCpp " << VERSION << std::endl;
		return 0;
	}

	std::vector lines = read_file(file);

	std::string include_dir, lib_dir, main_file, cpp_version;

	include_dir = "none";
	lib_dir = "none";
	main_file = "none";
	cpp_version = "11";

	int index = 1;

	std::vector<std::string> additional_files;

	for (std::string line : lines){
		std::vector<std::string> parts = split(line, ' ');

		if (parts.size() < 2 && parts.size() >= 1 && parts[0] != "run"){
			std::cerr << "Line " << std::to_string(index) << " does not enough arguments.\n";
			return 1;
		}

		if (parts[0] == "include_dir"){
			include_dir = parts[1];
		}

		if (parts[0] == "lib_dir"){
			lib_dir = parts[1];
		}

		if (parts[0] == "main_file"){
			main_file = parts[1];
		}

		if (parts[0] == "add_file"){
			additional_files.push_back(parts[1]);
		}

		if (parts[0] == "cpp_version"){
			cpp_version = parts[1];
		}

		index += 1;
	}

	std::string command = "g++ ";

	if (main_file != "none"){
		command += main_file;
	}
	
	if (include_dir != "none"){
		command += " -I" + include_dir;
	}

	if (lib_dir != "none"){
		command += " -L" + lib_dir;
	}

	for (const auto& file : additional_files){
		command += " " + file;
	}

	command += " -o " + split(main_file, '.')[0];
	command += " -std=c++" + cpp_version;

	std::system(command.c_str());


	if (lines[lines.size() - 1] == "run"){
		std::string cmd = "./" + split(main_file, '.')[0];
		std::system(cmd.c_str());
		return 0;
	}

	std::cout << "Succesfully built exe file '" << split(main_file, '.')[0] << "'!\nRun ./" << split(main_file, '.')[0] << " to run your masterpiece!\nOr Add 'run' at the end of the makefile to automatically run it\n";
 
	return 0;
}