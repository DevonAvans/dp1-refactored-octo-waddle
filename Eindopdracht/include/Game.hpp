#pragma once
#include <memory>
#include <string>

#include "Command/Command.hpp"
#include "Command/Key.h"
#include "State/Game/GameState.hpp"
#include "Visitor/CellSearchVisitor.hpp"
#include "Visitor/ValidationVisitor.hpp"

class Component;

class Game final
{
public:
	explicit Game(const std::string& file_path, std::unique_ptr<GameState> state);
	void stop();

	std::shared_ptr<Component> get_sudoku();
	void set_searcher_target(int row, int col) const;
	[[nodiscard]] Leaf* get_searcher_target() const;

	[[nodiscard]] bool solved() const;
	void check() const;
	void set_game_state(std::unique_ptr<GameState> state);
	void set_cell_value(Leaf& cell, int value) const;

	void execute_command(key key);

private:
	bool quit_;
	std::shared_ptr<Component> sudoku_;

	CellSearchVisitor* searcher_;
	std::unique_ptr<GameState> state_;
	std::unique_ptr<ValidationVisitor> validator_;
	std::unordered_map<key, std::unique_ptr<Command>> dictionary_;

	void load_commands();

	void change_final_state_value() const;
	void change_empty_to_helper() const;
};
