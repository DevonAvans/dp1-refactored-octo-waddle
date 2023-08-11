#include "State/Game/HelperGameState.hpp"

void HelperGameState::set_number(Leaf& cell, const int number)
{
	cell.add_candidates(number);
}
