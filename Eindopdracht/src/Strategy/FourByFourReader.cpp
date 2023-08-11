#include "Strategy/FourByFourReader.hpp"

#include "Composite/Composite.hpp"
#include "Composite/Leaf.hpp"

std::shared_ptr<Component> FourByFourReader::read(const std::string& path)
{
	const auto str = read_file(path);

	const auto sudoku = std::make_shared<Composite>();
	std::vector<std::shared_ptr<Composite>> sections(size_);

	for (int i = 0; i < size_; ++i)
	{
		sections[i] = std::make_shared<Composite>();
	}

	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			const auto index = i * size_ + j;
			const auto cell_value = std::stoi(str.substr(index, 1));
			const auto s_n = static_cast<int>(sqrt(size_));
			// (i / section_size) * num_sections_per_row + (j / section_size);
			const int section_number = (i / s_n) * s_n + (j / s_n);
			const auto cell = std::make_shared<Leaf>(CellAttributes(i, j, section_number), cell_value);
			sections[section_number]->add_child(cell);
		}
	}

	for (const auto section : sections)
	{
		sudoku->add_child(section);
	}

	return sudoku;
}
