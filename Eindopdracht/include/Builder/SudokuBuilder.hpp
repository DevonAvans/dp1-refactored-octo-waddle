#pragma once
#include "Composite/Component.hpp"

#include <memory>

#include "CellAttributes.hpp"

class SudokuBuilder
{
public:
	virtual void build_size(int size) = 0;
	virtual void build_cell(const CellAttributes& attributes, int value) const = 0;
	virtual std::shared_ptr<Component> get() = 0;
};
