#pragma once
#include <map>
#include <memory>
#include <string>

#include "Composite/Composite.hpp"

class SudokuReader;

class SudokuFactory
{
public:
	SudokuFactory();
	~SudokuFactory() = default;

	std::shared_ptr<Component> create(const std::string& path);

private:
	std::map<std::string, std::shared_ptr<SudokuReader>> dictionairy_;

	std::string get_extension(const std::string& path);
};
