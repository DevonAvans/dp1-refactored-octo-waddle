#include "Builder/SamuraiBuilder.hpp"
#include "Composite/Composite.hpp"

#include <vector>

#include "Util.hpp"

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
	std::vector<std::shared_ptr<Composite>> sections(sudoku_size_);

	ching_chong(sections, data, {offset, offset});
	sections.at(8) = top_left_;
	bind(sections);
}

void SamuraiBuilder::create_top_right(const std::string& data) const
{
	std::vector<std::shared_ptr<Composite>> sections(sudoku_size_);

	ching_chong(sections, data, {0, offset_});
	sections.at(6) = top_right_;
	bind(sections);
}

void SamuraiBuilder::create_middle(const std::string& data)
{
	const auto offset = offset_ / 2;
	const auto middle_sudoku = std::make_shared<Composite>();

	std::vector<std::shared_ptr<Composite>> sections(sudoku_size_);

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
	std::vector<std::shared_ptr<Composite>> sections(sudoku_size_);

	ching_chong(sections, data, {offset_, 0});
	sections.at(2) = bottom_left_;
	bind(sections);
}

void SamuraiBuilder::create_bottom_right(const std::string& data) const
{
	std::vector<std::shared_ptr<Composite>> sections(sudoku_size_);

	ching_chong(sections, data, {offset_, offset_});
	sections.at(0) = bottom_right_;
	bind(sections);
}

void SamuraiBuilder::ching_chong(std::vector<std::shared_ptr<Composite>>& sections, const std::string& data,
                                 const Offset offset) const
{
	for (int i = 0; i < sudoku_size_; ++i)
	{
		sections[i] = std::make_shared<Composite>();
	}

	auto i = 0;
	for (const auto& ch : data)
	{
		const int row = i / sudoku_size_;
		const int col = i % sudoku_size_;
		const auto cell_value = utils::safe_stoi(std::string(1, ch));
		const auto s_n = static_cast<int>(sqrt(sudoku_size_));
		//// (i / section_size) * num_sections_per_row + (j / section_size);
		const int section_number = (row / s_n) * s_n + (col / s_n);
		sections[section_number]->add_child(
			factory_->create({offset.row + row, offset.col + col, section_number, sudoku_size_}, cell_value)
		);
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

void SamuraiBuilder::build_size(int size)
{
}

void SamuraiBuilder::build_cell(const CellAttributes& attributes, int value) const
{
}
