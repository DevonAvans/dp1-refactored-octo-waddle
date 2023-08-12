#include "State/Cell/EmptyState.hpp"

#include "Composite/Leaf.hpp"
#include "State/Cell/NormalState.hpp"


void EmptyState::set_value(Leaf& cell, const int value)
{
	if (value == 0)
	{
		return;
	}
	set_cell_value(cell, value);
	cell.set_state(std::make_unique<NormalState>());
}

void EmptyState::set_valid(Leaf& cell, const bool value)
{
	set_cell_valid(cell, value);
}
