#pragma once

#include "SudokuReader.hpp"

class FourByFourReader final : public SudokuReader
{
public:
	std::shared_ptr<Component> read(const std::string& path) override;
	[[nodiscard]] int get_size() const override;

private:
	const int size_ = 4;
};
