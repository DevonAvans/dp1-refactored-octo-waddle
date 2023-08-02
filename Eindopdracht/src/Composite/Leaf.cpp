#include "Composite/Leaf.hpp"

Leaf::Leaf(int value) : value_{value}
{
}

int Leaf::get_value() const
{
	return value_;
}

void Leaf::display() const
{
}
