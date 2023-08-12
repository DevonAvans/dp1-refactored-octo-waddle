#pragma once
#include "GameState.hpp"

class DefinitiveGameState final : public GameState
{
public:
	void set_number(Leaf& cell, int number) override;
};
