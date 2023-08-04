#include "Composite/Leaf.hpp"
#include "Visitor/Visitor.hpp"

Leaf::Leaf(const int row, const int col, const int value) : row_{row}, col_{col}, value_{value}
{
}

void Leaf::display() const
{
}

void Leaf::accept(Visitor* visitor)
{
	visitor->visit_leaf(this);
}

int Leaf::get_value() const
{
	return value_;
}

int Leaf::get_row() const
{
	return row_;
}

int Leaf::get_col() const
{
	return col_;
}
