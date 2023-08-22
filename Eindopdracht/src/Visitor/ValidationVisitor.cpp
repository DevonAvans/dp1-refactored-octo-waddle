#include "Visitor/ValidationVisitor.hpp"

ValidationVisitor::ValidationVisitor(const int size) : size_{size}
{
}

void ValidationVisitor::visit_leaf(Leaf* leaf)
{
}

void ValidationVisitor::visit_composite(Composite* composite)
{
	for (const auto& child : composite->get_children())
	{
		if (auto cell = dynamic_cast<Leaf*>(child.get()))
		{
			const auto [row, col, section, max, sudoku] = cell->get_attributes();

			rows_[row].push_back(cell);
			cols_[col].push_back(cell);
			sections_[section].push_back(cell);

			cell->set_valid(true);
		}
		else
		{
			child->accept(this);
		}
	}

	for (int i = 0; i < size_; ++i)
	{
		check_uniqueness_and_update_validity(rows_[i]);
		check_uniqueness_and_update_validity(cols_[i]);
		check_uniqueness_and_update_validity(sections_[i]);
	}
}

void ValidationVisitor::reset()
{
	rows_.clear();
	cols_.clear();
	sections_.clear();
	rows_.resize(size_);
	cols_.resize(size_);
	sections_.resize(size_);
}

void ValidationVisitor::check_uniqueness_and_update_validity(const std::vector<Leaf*>& cells)
{
	std::unordered_map<int, int> value_counts;

	for (const Leaf* cell : cells)
	{
		int value = cell->get_value();
		value_counts[value]++;
	}

	for (Leaf* cell : cells)
	{
		if (value_counts[cell->get_value()] > 1)
		{
			cell->set_valid(false);
		}
	}
}
