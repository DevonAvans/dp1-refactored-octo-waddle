#pragma once
#include "GameState.hpp"

class HelperGameState : public GameState
{
public:
	void set_number(Leaf& cell, int number) override;
};
