#pragma once
#include "SudokuReader.hpp"

class SamuraiReader final : public SudokuReader
{
public:
	std::shared_ptr<Component> read(const std::string& path) override;

private:
	const int children_size_ = 5;
	const int sudoku_size_ = 81;
};
