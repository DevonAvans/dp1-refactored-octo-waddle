#include "Strategy/SamuraiReader.hpp"

#include <iostream>
#include <vector>

#include "Builder/SamuraiBuilder.hpp"
#include "Composite/Composite.hpp"
#include "Strategy/NineByNineReader.hpp"

std::shared_ptr<Component> SamuraiReader::read(const std::string& path)
{
	const auto str = read_file(path);
	std::vector<std::string> list;

	const auto samurai = std::make_shared<Composite>();

	int start_index = 0;
	for (int i = 0; i < children_size_; ++i)
	{
		if (start_index + sudoku_size_ <= str.size())
		{
			std::string sudoku = str.substr(start_index, sudoku_size_);
			list.emplace_back(sudoku);
			start_index += sudoku_size_;
		}
		else
		{
			std::cout << "Not enough content for sudoku " << i + 1 << std::endl;
		}
	}

	const auto middle_sudoku_str = list.at(2);

	SamuraiBuilder builder;
	builder.create_middle(middle_sudoku_str);
	builder.create_top_left(list.at(0));
	builder.create_top_right(list.at(1));
	builder.create_bottom_left(list.at(3));
	builder.create_bottom_right(list.at(4));

	//const auto size_ = 9;
	//auto sudoku_num = 0;
	//for (const auto& sudoku_str : list)
	//{
	//	const auto sudoku = std::make_shared<Composite>();

	//	std::vector<std::shared_ptr<Composite>> sections(size_);

	//	for (int i = 0; i < size_; ++i)
	//	{
	//		sections[i] = std::make_shared<Composite>();
	//	}

	//	for (int i = 0; i < size_; ++i)
	//	{
	//		for (int j = 0; j < size_; ++j)
	//		{
	//			const auto index = i * size_ + j;
	//			const auto cell_value = std::stoi(sudoku_str.substr(index, 1));
	//			const auto s_n = static_cast<int>(sqrt(size_));
	//			// (i / section_size) * num_sections_per_row + (j / section_size);
	//			const int section_number = (i / s_n) * s_n + (j / s_n);
	//			const auto cell = std::make_shared<Leaf>(CellAttributes(i, j, section_number, sudoku_num), cell_value);
	//			sections[section_number]->add_child(cell);
	//		}
	//	}

	//	for (const auto& section : sections)
	//	{
	//		sudoku->add_child(section);
	//	}

	//	++sudoku_num;
	//	samurai->add_child(sudoku);
	//}


	return builder.get();
}
