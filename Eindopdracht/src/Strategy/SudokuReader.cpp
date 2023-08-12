#include "Strategy/SudokuReader.hpp"

#include <iostream>
#include <fstream>
#include <vector>

SudokuReader::SudokuReader()
{
}

//SudokuReader::SudokuReader(std::unique_ptr<SudokuBuilder> builder): builder_{std::move(builder)}
//{
//}

std::string SudokuReader::read_file(const std::string& path) const
{
	std::vector<std::vector<std::string>> output;
	std::ifstream file{path};
	if (!file.is_open())
	{
		std::cerr << "couldnt open file" << std::endl;
		return "";
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
