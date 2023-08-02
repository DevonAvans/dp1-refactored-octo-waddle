#pragma once
#include <memory>

class Component;

class Game
{
public:
	explicit Game();
	void start();
	void update();
	void stop();

	std::shared_ptr<Component> get_sudoku();

private:
	bool quit_;
	std::shared_ptr<Component> sudoku_;
};
