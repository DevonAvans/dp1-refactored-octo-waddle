#include "Strategy/NineByNineReader.hpp"

#include "Composite/Composite.hpp"
#include "Composite/Leaf.hpp"

std::shared_ptr<Component> NineByNineReader::read(const std::string& path)
{
	const auto str = read_file(path);

	const auto sudoku = std::make_shared<Composite>();

	for (int i = 0; i < size_; ++i)
	{
		const auto row = std::make_shared<Composite>();

		for (int j = 0; j < size_; ++j)
		{
			const auto index = i * size_ + j;
			const auto cell_value = std::stoi(str.substr(index, 1));
			const auto cell = std::make_shared<Leaf>(CellAttributes(i, j), cell_value);
			row->add_child(cell);
		}
		sudoku->add_child(row);
	}

	return sudoku;
}
