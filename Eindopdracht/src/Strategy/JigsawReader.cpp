#include "Strategy/JigsawReader.hpp"

#include <iostream>

#include "CellAttributes.hpp"
#include "Composite/Composite.hpp"
#include "Composite/Leaf.hpp"

std::shared_ptr<Component> JigsawReader::read(const std::string& path)
{
	auto str = read_file(path);

	if (str.find(prefix_) != 0)
	{
		return nullptr;
	}

	str = str.substr(prefix_.length());

	const auto sudoku = std::make_shared<Composite>();
	std::vector<std::shared_ptr<Composite>> sections(size_);

	for (int i = 0; i < size_; ++i)
	{
		sections[i] = std::make_shared<Composite>();
	}

	std::vector<std::string> segments;
	size_t start = 0;
	size_t end = str.find('=');

	while (start < str.length())
	{
		if (end == std::string::npos)
		{
			end = str.length();
		}

		const auto segment = str.substr(start, end - start);
		if (!segment.empty())
		{
			segments.push_back(segment);
		}

		start = end + 1;
		end = str.find('=', start);
	}

	if (start < str.length())
	{
		segments.push_back(str.substr(start));
	}

	for (auto i = 0; i < segments.size(); ++i)
	{
		const auto segment = segments.at(i);
		const size_t j_pos = segment.find('J');

		if (j_pos != std::string::npos)
		{
			const auto value = std::stoi(segment.substr(0, j_pos));
			const auto section = std::stoi(segment.substr(j_pos + 1));

			const int row = i / 9;
			const int col = i % 9;

			sections[section]->add_child(
				std::make_shared<Leaf>(CellAttributes{row, col, section}, value));
		}
	}

	for (const auto& section : sections)
	{
		sudoku->add_child(section);
	}

	return sudoku;
}
