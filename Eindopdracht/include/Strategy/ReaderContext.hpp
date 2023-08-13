#pragma once
#include <map>
#include <memory>
#include <string>

#include "Composite/Composite.hpp"

class SudokuReader;

// TODO: Low binding factory
class ReaderContext
{
public:
	ReaderContext();
	~ReaderContext() = default;

	std::shared_ptr<Component> read(const std::string& path);

private:
	std::map<std::string, std::shared_ptr<SudokuReader>> dictionairy_;

	static std::string get_extension(const std::string& path);
};
