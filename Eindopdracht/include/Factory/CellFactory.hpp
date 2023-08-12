#pragma once
#include "AbstractFactory.hpp"
#include "CellAttributes.hpp"

class CellFactory
{
public:
	std::shared_ptr<Component> create(const CellAttributes& attributes, int initial_value) const;
};
