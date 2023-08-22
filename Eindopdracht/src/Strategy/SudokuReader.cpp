#include "Strategy/SudokuReader.hpp"

#include <fstream>
#include <vector>

SudokuReader::SudokuReader()
{
}

std::string SudokuReader::read_file(const std::string& path) const
{
	std::vector<std::vector<std::string>> output;
	std::ifstream file{path};
	if (!file.is_open())
	{
		throw std::runtime_error("Failed to open the file.");
	}
	std::string content;
	std::string line;

	while (std::getline(file, line))
	{
		content += line;
	}

	file.close();

	return content;
}
