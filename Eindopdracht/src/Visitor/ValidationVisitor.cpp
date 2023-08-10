#include "Visitor/ValidationVisitor.hpp"

ValidationVisitor::ValidationVisitor()
{
}

void ValidationVisitor::visit_leaf(Leaf* leaf)
{
	valid_ = validate_row() && validate_col() && validate_section();
}

void ValidationVisitor::visit_composite(Composite* composite)
{
	for (const auto& child : composite->get_children())
	{
		child->accept(this);
	}
}

bool ValidationVisitor::validate_row()
{
	return true;
}

bool ValidationVisitor::validate_col()
{
	return true;
}

bool ValidationVisitor::validate_section()
{
	return true;
}
