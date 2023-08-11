#pragma once
#include "Composite/Leaf.hpp"

class GameState
{
public:
	virtual void set_number(Leaf& cell, int number) = 0;
};
