#include "Visitor/CellSearchVisitor.hpp"

CellSearchVisitor::CellSearchVisitor(const int row, const int col) : target_row_{row}, target_col_{col}
{
}

void CellSearchVisitor::visit_leaf(Leaf* leaf)
{
	const int row = leaf->get_row();
	const int col = leaf->get_col();

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

void CellSearchVisitor::set_target(const int row, const int col)
{
	target_row_ = row;
	target_col_ = col;
}

Leaf* CellSearchVisitor::get_cell() const
{
	return cell_;
}
