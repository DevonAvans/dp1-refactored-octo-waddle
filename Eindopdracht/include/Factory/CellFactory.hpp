#pragma once
#include <memory>

#include "CellAttributes.hpp"

class Component;

class CellFactory
{
public:
	[[nodiscard]] std::shared_ptr<Component> create(const CellAttributes& attributes, int initial_value) const;
};
