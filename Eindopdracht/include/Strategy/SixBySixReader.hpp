#pragma once
#include "SudokuReader.hpp"

class SixBySixReader : public SudokuReader
{
public:
	std::shared_ptr<Component> read(const std::string& path) override;
};
