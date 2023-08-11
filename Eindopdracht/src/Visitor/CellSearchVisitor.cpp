#include "Visitor/CellSearchVisitor.hpp"

CellSearchVisitor::CellSearchVisitor()
	: target_row_{0}, target_col_{0}
{
}

void CellSearchVisitor::visit_leaf(Leaf* leaf)
{
	const auto [row, col, section, sudoku] = leaf->get_attributes();

	if (target_row_ == row && target_col_ == col)
	{
		cell_ = leaf;
	}
}

void CellSearchVisitor::visit_composite(Composite* composite)
{
	for (const auto& component : composite->get_children())
	{
		component->accept(this);
		if (cell_ != nullptr)
		{
			break;
		}
	}
}

void CellSearchVisitor::set_target(const int row, const int col, const int sudoku)
{
	target_row_ = row;
	target_col_ = col;
	target_sudoku_ = sudoku;
	cell_ = nullptr;
}

Leaf* CellSearchVisitor::get_cell() const
{
	return cell_;
}
