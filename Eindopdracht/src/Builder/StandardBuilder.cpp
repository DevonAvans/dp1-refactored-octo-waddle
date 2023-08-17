#include "Builder/StandardBuilder.hpp"

void StandardBuilder::build_size(const int size)
{
	size_ = size;
	sudoku_ = std::make_shared<Composite>();
	sections_.resize(size);

	for (int i = 0; i < size; ++i)
	{
		sections_[i] = std::make_shared<Composite>();
	}
}

void StandardBuilder::build_cell(const CellAttributes& attributes, const int value) const
{
	sections_[attributes.section]->add_child(
		factory_->create({attributes.row, attributes.col, attributes.section, size_}, value));
}

std::shared_ptr<Component> StandardBuilder::get()
{
	for (const auto& section : sections_)
	{
		sudoku_->add_child(section);
	}
	return sudoku_;
}
