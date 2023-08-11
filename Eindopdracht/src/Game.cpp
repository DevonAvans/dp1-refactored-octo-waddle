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
}

void Game::start()
{
	//const auto visitor = new SudokuVisitor();

	//change_final_state_value();
	//change_empty_to_helper();
}

void Game::update()
{
}

void Game::stop()
{
	quit_ = true;
}

std::shared_ptr<Component> Game::get_sudoku()
{
	return sudoku_;
}

void Game::set_searcher_target(const int row, const int col, const int sudoku) const
{
	searcher_->set_target(row, col, sudoku);
	sudoku_->accept(searcher_);
}

Leaf* Game::get_searcher_target() const
{
	return searcher_->get_cell();
}

void Game::set_game_state(std::unique_ptr<GameState> state)
{
	state_ = std::move(state);
}

void Game::set_cell_value(Leaf& cell, const int value) const
{
	state_->set_number(cell, value);
}

void Game::validate_rows()
{
}

void Game::validate_cols()
{
}

void Game::validate_sections()
{
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
