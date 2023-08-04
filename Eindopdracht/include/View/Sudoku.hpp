#pragma once
#include <memory>

class Component;

class Sudoku
{
public:
	explicit Sudoku(std::shared_ptr<Component>& sudoku);
	void render();

private:
	std::shared_ptr<Component>& sudoku_;
};
