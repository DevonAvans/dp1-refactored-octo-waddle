#pragma once
#include "SudokuReader.hpp"

class JigsawReader : public SudokuReader
{
public:
	std::shared_ptr<Component> read(const std::string& path) override;
};
