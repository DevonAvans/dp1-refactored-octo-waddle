#pragma once
#include <memory>
#include <string>

class Component;

class SudokuReader
{
public:
	virtual std::shared_ptr<Component> read(const std::string& path) = 0;
protected:
	[[nodiscard]] std::string read_file(const std::string& path) const;
};