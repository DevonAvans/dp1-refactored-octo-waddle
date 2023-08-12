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


	return builder.get();
}
