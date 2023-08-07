#include "State/EmptyState.hpp"

#include "State/HelperState.hpp"

//void EmptyState::enter_definitive_state(Leaf& cell)
//{
//}
//
//void EmptyState::enter_hulp_state(Leaf& cell)
//{
//}
//
//void EmptyState::enter_empty(Leaf& cell)
//{
//}

void EmptyState::set_value(Leaf& cell, const int value)
{
	if (value == 0)
	{
		return;
	}
	set_cell_value(cell, value);
	cell.set_state(new HelperState());
}

//bool EmptyState::can_set_value() const
//{
//	return true;
//}
