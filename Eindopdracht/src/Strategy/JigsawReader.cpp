#include "Strategy/JigsawReader.hpp"

#include <iostream>

#include "Util.hpp"
#include "Builder/StandardBuilder.hpp"
#include "Composite/Leaf.hpp"

std::shared_ptr<Component> JigsawReader::read(const std::string& path)
{
	auto str = read_file(path);

	if (str.find(prefix_) != 0)
	{
		return nullptr;
	}

	str = str.substr(prefix_.length());

	const auto builder = std::make_unique<StandardBuilder>();

	builder->build_size(size_);

	std::vector<std::string> segments;
	size_t start = 0;
	size_t end = str.find(cell_sep_);

	while (start < str.length())
	{
		if (end == std::string::npos)
		{
			end = str.length();
		}

		const auto& segment = str.substr(start, end - start);
		if (!segment.empty())
		{
			segments.push_back(segment);
		}

		start = end + 1;
		end = str.find('=', start);
	}

	if (start < str.length())
	{
		segments.push_back(str.substr(start));
	}

	for (auto i = 0; i < segments.size(); ++i)
	{
		const auto segment = segments.at(i);
		const size_t j_pos = segment.find(value_sep_);

		if (j_pos != std::string::npos)
		{
			const auto value = utils::safe_stoi(
				segment.substr(0, j_pos)
			);
			const auto section = utils::safe_stoi(
				segment.substr(j_pos + 1)
			);

			const int row = i / 9;
			const int col = i % 9;

			builder->build_cell({row, col, section, size_}, value);
		}
	}

	return builder->get();
}

int JigsawReader::get_size() const
{
	return size_;
}
