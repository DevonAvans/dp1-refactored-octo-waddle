#pragma once

#include "SudokuReader.hpp"

class FourByFourReader final : public SudokuReader
{
public:
	std::shared_ptr<Component> read(const std::string& path) override;

private:
	int size_ = 4;
};
