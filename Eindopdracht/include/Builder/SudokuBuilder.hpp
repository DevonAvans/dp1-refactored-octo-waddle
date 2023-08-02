#pragma once
#include "Composite/Component.hpp"

class SudokuBuilder
{
public:
	virtual Component* get() = 0;
};
