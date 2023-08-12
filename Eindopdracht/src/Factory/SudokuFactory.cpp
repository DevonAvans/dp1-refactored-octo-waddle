#include "Factory/SudokuFactory.hpp"

#include <string>

#include "Composite/Composite.hpp"
#include "Composite/Leaf.hpp"
#include <Factory/CellFactory.hpp>

std::shared_ptr<Component> SudokuFactory::create(const std::string& str)
{
	const CellFactory cell_factory;
	const auto size = static_cast<int>(sqrt(str.length()));
	const auto sudoku = std::make_shared<Composite>();
	std::vector<std::shared_ptr<Composite>> sections(size);

	for (int i = 0; i < size; ++i)
	{
		sections[i] = std::make_shared<Composite>();
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			const auto index = i * size + j;
			const auto cell_value = std::stoi(str.substr(index, 1));
			const auto s_n = static_cast<int>(sqrt(size));
			// (i / section_size) * num_sections_per_row + (j / section_size);
			const int section_number = (i / s_n) * s_n + (j / s_n);
			sections[section_number]->add_child(cell_factory.create({i, j, section_number}, cell_value));
		}
	}

	for (const auto& section : sections)
	{
		sudoku->add_child(section);
	}

	return sudoku;
}
