#pragma once
#include "SudokuBuilder.hpp"

class SamuraiBuilder final : public SudokuBuilder
{
	Component* get() override;
};
