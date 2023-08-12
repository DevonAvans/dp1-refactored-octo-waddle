#include "State/CellState.hpp"

#include "Composite/Leaf.hpp"

void CellState::set_cell_value(Leaf& cell, const int value)
{
	cell.value_ = value;
}

void CellState::set_cell_valid(Leaf& cell, const bool valid)
{
	cell.valid_ = valid;
}
