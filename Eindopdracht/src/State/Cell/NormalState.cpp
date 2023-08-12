#include "State/Cell/NormalState.hpp"

#include "Composite/Leaf.hpp"
#include "State/Cell/EmptyState.hpp"

void NormalState::set_value(Leaf& cell, const int value)
{
	if (value == 0)
	{
		cell.set_state(std::make_unique<EmptyState>());
	}
	set_cell_value(cell, value);
}

void NormalState::set_valid(Leaf& cell, const bool value)
{
	set_cell_valid(cell, value);
}
