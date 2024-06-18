#ifndef FILE_IO_HPP
#pragma FILE_IO_HPP

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Function to split a string by a delimiter
inline std::vector<std::string> split(std::string str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}

inline std::vector<std::string> read_file(std::string file_name){
	std::vector<std::string> v;

	std::ifstream file(file_name);

	std::string line;
    while (std::getline(file, line)) {
        v.push_back(line);
    }

    return v;
}

#endif