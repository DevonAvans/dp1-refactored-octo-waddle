#include "Builder/SamuraiBuilder.hpp"
#include "Composite/Composite.hpp"

#include <vector>

#include "CellAttributes.hpp"
#include "Composite/Leaf.hpp"

SamuraiBuilder::SamuraiBuilder():
	value_{std::make_shared<Composite>()}
{
}

std::shared_ptr<Component> SamuraiBuilder::get()
{
	return value_;
}

void SamuraiBuilder::create_top_left(const std::string& data) const
{
	const auto offset = 0;
	std::vector<std::shared_ptr<Composite>> sections(9);

	ching_chong(sections, data, {offset, offset});
	sections.at(8) = top_left_;
	bind(sections);
}

void SamuraiBuilder::create_top_right(const std::string& data) const
{
	std::vector<std::shared_ptr<Composite>> sections(9);

	ching_chong(sections, data, {0, 12});
	sections.at(6) = top_right_;
	bind(sections);
}

void SamuraiBuilder::create_middle(const std::string& data)
{
	const auto offset = 6;
	const auto middle_sudoku = std::make_shared<Composite>();

	std::vector<std::shared_ptr<Composite>> sections(9);

	ching_chong(sections, data, {offset, offset});

	for (const auto& section : sections)
	{
		middle_sudoku->add_child(section);
	}

	top_left_ = sections.at(0);
	top_right_ = sections.at(2);
	bottom_left_ = sections.at(6);
	bottom_right_ = sections.at(8);

	value_->add_child(middle_sudoku);
}

void SamuraiBuilder::create_bottom_left(const std::string& data) const
{
	std::vector<std::shared_ptr<Composite>> sections(9);

	ching_chong(sections, data, {12, 0});
	sections.at(2) = bottom_left_;
	bind(sections);
}

void SamuraiBuilder::create_bottom_right(const std::string& data) const
{
	std::vector<std::shared_ptr<Composite>> sections(9);

	ching_chong(sections, data, {12, 12});
	sections.at(0) = bottom_right_;
	bind(sections);
}

void SamuraiBuilder::ching_chong(std::vector<std::shared_ptr<Composite>>& sections, const std::string& data,
                                 const Offset offset) const
{
	for (int i = 0; i < 9; ++i)
	{
		sections[i] = std::make_shared<Composite>();
	}

	auto i = 0;
	for (const auto& ch : data)
	{
		const int row = i / 9;
		const int col = i % 9;
		const auto cell_value = std::stoi(std::string(1, ch));
		const auto s_n = static_cast<int>(sqrt(9));
		//// (i / section_size) * num_sections_per_row + (j / section_size);
		const int section_number = (row / s_n) * s_n + (col / s_n);
		const auto cell = std::make_shared<Leaf>(CellAttributes(offset.row + row, offset.col + col, section_number),
		                                         cell_value);
		sections[section_number]->add_child(cell);
		++i;
	}
}

void SamuraiBuilder::bind(
	const std::vector<std::shared_ptr<Composite>>& sections) const
{
	const auto sudoku = std::make_shared<Composite>();
	for (const auto& section : sections)
	{
		sudoku->add_child(section);
	}
	value_->add_child(sudoku);
}
