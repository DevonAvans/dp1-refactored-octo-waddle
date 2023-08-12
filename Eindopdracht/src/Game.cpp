#include "Game.hpp"

#include <iostream>

#include "State/Game/DefinitiveGameState.hpp"
#include "Strategy/ReaderContext.hpp"
#include "Visitor/CellSearchVisitor.hpp"
#include "Visitor/SudokuVisitor.hpp"

Game::Game(const std::string& file_path, std::unique_ptr<GameState> state) : quit_{false}
{
	ReaderContext context;
	//todo error handle
	sudoku_ = context.read(file_path);
	searcher_ = new CellSearchVisitor();
	state_ = std::move(state);
	validator_ = std::make_unique<ValidationVisitor>(21);
}

void Game::stop()
{
	quit_ = true;
}

std::shared_ptr<Component> Game::get_sudoku()
{
	return sudoku_;
}

void Game::set_searcher_target(const int row, const int col) const
{
	searcher_->set_target(row, col);
	sudoku_->accept(searcher_);
}

Leaf* Game::get_searcher_target() const
{
	return searcher_->get_cell();
}

bool Game::solved() const
{
	return sudoku_->is_valid();
}

void Game::check()
{
	validator_->reset();
	sudoku_->accept(validator_.get());
}

void Game::set_game_state(std::unique_ptr<GameState> state)
{
	state_ = std::move(state);
}

void Game::set_cell_value(Leaf& cell, const int value) const
{
	state_->set_number(cell, value);
}

void Game::change_final_state_value() const
{
	searcher_->set_target(0, 1);
	sudoku_->accept(searcher_);
	const auto leaf = searcher_->get_cell();
	leaf->set_value(1);
	std::cout << "" << std::endl;
}

void Game::change_empty_to_helper() const
{
	searcher_->set_target(0, 0);
	sudoku_->accept(searcher_);
	const auto leaf2 = searcher_->get_cell();
	leaf2->set_value(5);
	std::cout << "" << std::endl;
}
