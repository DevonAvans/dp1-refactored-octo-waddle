#include "Game.hpp"

#include <iostream>

#include "Command/Command.hpp";
#include "Command/CheckCommand.hpp"
#include "Command/DefinitiveCommand.hpp"
#include "Command/HelperCommand.hpp"
#include "Command/LoadPuzzle.hpp"
#include "Factory/SudokuFactory.hpp"
#include "Visitor/CellSearchVisitor.hpp"
#include "Visitor/SudokuVisitor.hpp"
#include "Strategy/SudokuReader.hpp"

Game::Game(const std::string& file_path, std::unique_ptr<GameState> state) :
	quit_{false}, factory_{std::make_unique<SudokuFactory>()}
{
	state_ = std::move(state);
	start(file_path);
}

void Game::start(const std::string& file_path)
{
	const auto reader = factory_->create(file_path);
	sudoku_ = reader->read(file_path);
	if (sudoku_ == nullptr)
	{
		throw std::runtime_error("Failed to read Sudoku from file.");
	}
	searcher_ = std::make_unique<CellSearchVisitor>();
	validator_ = std::make_unique<ValidationVisitor>(reader->get_size());
	load_commands();
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
	sudoku_->accept(searcher_.get());
}

Leaf* Game::get_searcher_target() const
{
	return searcher_->get_cell();
}

bool Game::solved() const
{
	return sudoku_->is_valid();
}

void Game::check() const
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

void Game::execute_command(const key key)
{
	if (dictionary_.contains(key))
	{
		dictionary_[key]->execute();
	}
}

void Game::load_commands()
{
	dictionary_[key::Check] = std::make_unique<CheckCommand>(*this);
	dictionary_[key::Definitive] = std::make_unique<DefinitiveCommand>(*this);
	dictionary_[key::Helper] = std::make_unique<HelperCommand>(*this);
	dictionary_[key::LoadPuzzle] = std::make_unique<LoadPuzzle>(*this);
}

void Game::change_final_state_value() const
{
	searcher_->set_target(0, 1);
	sudoku_->accept(searcher_.get());
	const auto leaf = searcher_->get_cell();
	leaf->set_value(1);
	std::cout << "" << std::endl;
}

void Game::change_empty_to_helper() const
{
	searcher_->set_target(0, 0);
	sudoku_->accept(searcher_.get());
	const auto leaf2 = searcher_->get_cell();
	leaf2->set_value(5);
	std::cout << "" << std::endl;
}
