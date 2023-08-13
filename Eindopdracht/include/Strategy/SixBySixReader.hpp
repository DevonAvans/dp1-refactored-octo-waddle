#pragma once
#include "SudokuReader.hpp"

class SixBySixReader : public SudokuReader
{
public:
	std::shared_ptr<Component> read(const std::string& path) override;
	[[nodiscard]] int get_size() const override;

private:
	const int size_ = 6;
	const int section_width_ = 3;
	const int section_height_ = 2;
};
