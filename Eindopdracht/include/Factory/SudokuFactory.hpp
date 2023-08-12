#pragma once
#include "AbstractFactory.hpp"

class SudokuFactory : public AbstractFactory
{
public:
	std::shared_ptr<Component> create(const std::string& str) override;
};
