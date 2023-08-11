#pragma once
#include "SudokuBuilder.hpp"

class StandardBuilder : SudokuBuilder
{
	std::shared_ptr<Component> get() override;
};
