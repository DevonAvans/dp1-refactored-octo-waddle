#pragma once
#include <memory>
#include <string>

#include "Composite/Component.hpp"

class AbstractFactory
{
public:
	virtual std::shared_ptr<Component> create(const std::string& str) = 0;
};
