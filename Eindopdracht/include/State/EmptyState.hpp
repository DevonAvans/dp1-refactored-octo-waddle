#pragma once
#include "CellState.hpp"

class EmptyState : public CellState
{
public:
	//void enter_definitive_state(Leaf& cell) override;
	//void enter_hulp_state(Leaf& cell) override;
	//void enter_empty(Leaf& cell) override;
	void set_value(Leaf& cell, int value) override;
	//[[nodiscard]] bool can_set_value() const override;
};
