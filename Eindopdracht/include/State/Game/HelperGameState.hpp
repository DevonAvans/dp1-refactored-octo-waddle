#pragma once
#include "GameState.hpp"

class HelperGameState final : public GameState
{
public:
	void set_number(Leaf& cell, int number) override;
};
