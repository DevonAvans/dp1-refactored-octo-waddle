#pragma once
#include "Composite/Leaf.hpp"

class CellState
{
public:
	//virtual void enter_definitive_state(Leaf& cell) = 0;
	//virtual void enter_hulp_state(Leaf& cell) = 0;
	//virtual void enter_empty(Leaf& cell) = 0;
	virtual void set_value(Leaf& cell, int value) = 0;

	[[nodiscard]] virtual bool can_set_value() const
	{
		return false;
	}
};
