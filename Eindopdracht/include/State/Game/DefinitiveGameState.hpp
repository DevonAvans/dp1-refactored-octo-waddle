#pragma once
#include "GameState.hpp"

class DefinitiveGameState : public GameState
{
public:
	void set_number(Leaf& cell, int number) override;
};
