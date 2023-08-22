#include "Strategy/NineByNineReader.hpp"

#include "Util.hpp"
#include "Builder/StandardBuilder.hpp"

std::shared_ptr<Component> NineByNineReader::read(const std::string& path)
{
	const auto builder = std::make_unique<StandardBuilder>();
	const auto str = read_file(path);
	builder->build_size(size_);
	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			const auto index = i * size_ + j;
			const auto cell_value = utils::safe_stoi(str.substr(index, 1));
			const auto s_n = static_cast<int>(sqrt(size_));
			// (i / section_size) * num_sections_per_row + (j / section_size);
			const int section_number = (i / s_n) * s_n + (j / s_n);
			builder->build_cell({i, j, section_number, size_}, cell_value);
		}
	}
	return builder->get();
}

int NineByNineReader::get_size() const
{
	return size_;
}
