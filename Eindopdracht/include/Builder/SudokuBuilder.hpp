#pragma once
#include "Composite/Component.hpp"

#include <memory>

class SudokuBuilder
{
public:
	virtual std::shared_ptr<Component> get() = 0;
};
