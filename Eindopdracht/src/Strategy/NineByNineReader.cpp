#include "Strategy/NineByNineReader.hpp"

#include "Composite/Composite.hpp"
#include "Composite/Leaf.hpp"

std::shared_ptr<Component> NineByNineReader::read(const std::string& path)
{
	const auto str = read_file(path);

	/*const auto sudoku = std::make_shared<Composite>();

	for (int i = 0; i < 9; ++i)
	{
		const auto row = std::make_shared<Composite>();

		for (int j = 0; j < 9; ++j)
		{
			const auto index = i * 9 + j;
			const auto cell_value = std::stoi(str.substr(index, 1));
			const auto cell = std::make_shared<Leaf>(cell_value);
			row->add_child(cell);
		}
		sudoku->add_child(row);
	}*/

	return nullptr;
}
