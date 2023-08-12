#pragma once
#include <memory>
#include <string>

#include "Builder/SudokuBuilder.hpp"

class Component;

class SudokuReader
{
public:
	explicit SudokuReader();
	//explicit SudokuReader(std::unique_ptr<SudokuBuilder> builder);
	virtual std::shared_ptr<Component> read(const std::string& path) = 0;
protected:
	[[nodiscard]] std::string read_file(const std::string& path) const;
	//std::unique_ptr<SudokuBuilder> builder_;
};
