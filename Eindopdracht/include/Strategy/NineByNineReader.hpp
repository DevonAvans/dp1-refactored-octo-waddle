#pragma once

#include "SudokuReader.hpp"

class NineByNineReader final : public SudokuReader
{
public:
	std::shared_ptr<Component> read(const std::string& path) override;

private:
	const int size_ = 9;
};
