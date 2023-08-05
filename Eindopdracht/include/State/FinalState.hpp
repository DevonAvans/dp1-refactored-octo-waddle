#pragma once
#include "CellState.hpp"

class FinalState : public CellState
{
public:
	//void enter_definitive_state(Leaf& cell) override;
	//void enter_hulp_state(Leaf& cell) override;
	//void enter_empty(Leaf& cell) override;
	void set_value(Leaf& cell, int value) override;
};
