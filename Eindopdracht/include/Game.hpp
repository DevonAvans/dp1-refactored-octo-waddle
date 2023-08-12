#pragma once
#include <memory>
#include <string>

#include "State/Game/GameState.hpp"
#include "Visitor/CellSearchVisitor.hpp"
#include "Visitor/ValidationVisitor.hpp"

class Component;

class Game final
{
public:
	explicit Game(const std::string& file_path, std::unique_ptr<GameState> state);
	void start();
	void update();
	void stop();

	std::shared_ptr<Component> get_sudoku();
	void set_searcher_target(int row, int col, int sudoku = 0) const;
	[[nodiscard]] Leaf* get_searcher_target() const;

	bool is_valid() const;
	void check();
	void set_game_state(std::unique_ptr<GameState> state);
	void set_cell_value(Leaf& cell, int value) const;

private:
	bool quit_;
	std::shared_ptr<Component> sudoku_;

	CellSearchVisitor* searcher_;
	std::unique_ptr<GameState> state_;
	std::unique_ptr<ValidationVisitor> validator_;

	void change_final_state_value() const;
	void change_empty_to_helper() const;
};
