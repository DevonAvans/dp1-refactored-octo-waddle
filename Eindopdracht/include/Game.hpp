#pragma once
#include <memory>

#include "Visitor/CellSearchVisitor.hpp"

class Configuration;
class Component;

class Game
{
public:
	explicit Game();
	void start();
	void update();
	void stop();

	std::shared_ptr<Component> get_sudoku();
	void set_searcher_target(int row, int col) const;
	[[nodiscard]] Leaf* get_searcher_target() const;

private:
	bool quit_;
	std::shared_ptr<Component> sudoku_;
	CellSearchVisitor* searcher_;
	//std::unique_ptr<Configuration> config_;

	void change_final_state_value() const;
	void change_empty_to_helper() const;
};
