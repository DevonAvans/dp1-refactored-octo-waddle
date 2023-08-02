#pragma once
#include <map>
#include <memory>
#include <string>

#include "Composite/Composite.hpp"

class SudokuReader;

class ReaderContext
{
public:
	ReaderContext();
	~ReaderContext();

	void set_strategy(std::shared_ptr<SudokuReader> reader);

	std::shared_ptr<Component> read(const std::string& path);

private:
	std::map<std::string, std::shared_ptr<SudokuReader>> dictionairy_;

	std::string get_extension(const std::string& path);
};
