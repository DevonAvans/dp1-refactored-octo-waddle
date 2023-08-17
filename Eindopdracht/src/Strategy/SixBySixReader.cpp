#include "Strategy/SixBySixReader.hpp"

#include "Util.hpp"
#include "Builder/StandardBuilder.hpp"

std::shared_ptr<Component> SixBySixReader::read(const std::string& path)
{
	const auto builder = std::make_unique<StandardBuilder>();
	const auto str = read_file(path);
	builder->build_size(size_);

	const int num_sections_per_row = size_ / section_width_;

	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			const auto index = i * size_ + j;
			const auto cell_value = utils::safe_stoi(str.substr(index, 1));

			const int section_row = i / section_height_;
			const int section_col = j / section_width_;
			const int section_number = section_row * num_sections_per_row + section_col;

			builder->build_cell({i, j, section_number, size_}, cell_value);
		}
	}

	return builder->get();
}

int SixBySixReader::get_size() const
{
	return size_;
}
