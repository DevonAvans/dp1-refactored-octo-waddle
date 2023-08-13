#pragma once
#include "SudokuReader.hpp"

class JigsawReader : public SudokuReader
{
public:
	std::shared_ptr<Component> read(const std::string& path) override;
	[[nodiscard]] int get_size() const override;

private:
	const int size_ = 9;
	const std::string prefix_ = "SumoCueV1";
};
