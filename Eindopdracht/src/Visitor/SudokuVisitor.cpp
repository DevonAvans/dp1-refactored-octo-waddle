#include "Visitor/SudokuVisitor.hpp"

#include <iostream>
#include <ostream>

void SudokuVisitor::visit_leaf(Leaf* leaf)
{
	const auto value = leaf->get_value();
	std::cout << "Hallo" << std::endl;
}

void SudokuVisitor::visit_composite(Composite* composite)
{
	for (const auto& child : composite->get_children())
	{
		child->accept(this);
	}
}
