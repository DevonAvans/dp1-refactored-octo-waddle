#include "State/HelperState.hpp"

#include "State/EmptyState.hpp"

//void HelperState::enter_definitive_state(Leaf& cell)
//{
//}
//
//void HelperState::enter_hulp_state(Leaf& cell)
//{
//}
//
//void HelperState::enter_empty(Leaf& cell)
//{
//}

void HelperState::set_value(Leaf& cell, const int value)
{
	if (value == 0)
	{
		cell.set_state(new EmptyState());
	}
	cell.set_raw_value(value);
}
