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
		Leaf* cell = dynamic_cast<Leaf*>(child.get());
		if (cell)
		{
			const auto [row, col, section, sudoku] = cell->get_attributes();

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

	// Check for uniqueness and set valid_ flag accordingly
	for (int i = 0; i < size_; ++i)
	{
		CheckUniquenessAndUpdateValidity(rows_[i]);
		CheckUniquenessAndUpdateValidity(cols_[i]);
		CheckUniquenessAndUpdateValidity(sections_[i]);
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
