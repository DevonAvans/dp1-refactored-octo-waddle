#include "Strategy/SixBySixReader.hpp"

#include "CellAttributes.hpp"
#include "Composite/Composite.hpp"
#include "Composite/Leaf.hpp"

std::shared_ptr<Component> SixBySixReader::read(const std::string& path)
{
	const auto str = read_file(path);

	const auto sudoku = std::make_shared<Composite>();
	std::vector<std::shared_ptr<Composite>> sections(size_);

	for (int i = 0; i < size_; ++i)
	{
		sections[i] = std::make_shared<Composite>();
	}

	const int num_sections_per_row = size_ / section_width_;

	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			const auto index = i * size_ + j;
			const auto cell_value = std::stoi(str.substr(index, 1));

			const int section_row = i / section_height_;
			const int section_col = j / section_width_;
			const int section_number = section_row * num_sections_per_row + section_col;

			//const auto cell = std::make_shared<Leaf>(CellAttributes(i, j, section_number), cell_value);
			//sections[section_number]->add_child(cell);
		}
	}

	for (const auto& section : sections)
	{
		sudoku->add_child(section);
	}

	return sudoku;
}
