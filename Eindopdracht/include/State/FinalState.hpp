#pragma once
#include "CellState.hpp"

class FinalState : public CellState
{
public:
	void set_value(Leaf& cell, int value) override;
	void set_valid(Leaf& cell, bool value) override;
};
