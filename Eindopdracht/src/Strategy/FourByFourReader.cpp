#include "Strategy/FourByFourReader.hpp"

#include <ostream>

#include "CellAttributes.hpp"
#include "Composite/Composite.hpp"
#include "Composite/Leaf.hpp"

std::shared_ptr<Component> FourByFourReader::read(const std::string& path)
{
	// TODO: MAAK HIER EERST EEN PUZZLE CONFIG EN DIE DELEN MET ALLE LEAFS, EVT OPSLAAN IN COMPOSITE
	const auto str = read_file(path);

	const auto sudoku = std::make_shared<Composite>();

	for (int i = 0; i < 4; ++i)
	{
		const auto row = std::make_shared<Composite>();

		for (int j = 0; j < 4; ++j)
		{
			const auto index = i * 4 + j;
			const auto cell_value = std::stoi(str.substr(index, 1));
			const auto cell = std::make_shared<Leaf>(CellAttributes(i, j), cell_value);
			row->add_child(cell);
		}
		sudoku->add_child(row);
	}

	return sudoku;
}
