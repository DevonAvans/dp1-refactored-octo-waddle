#pragma once
#include "Composite/Leaf.hpp"

class CellState
{
public:
	virtual void set_value(Leaf& cell, int value) = 0;
protected:
	virtual void set_cell_value(Leaf& cell, const int value)
	{
		cell.value_ = value;
	}
};
