#include "Game.hpp"

#include <iostream>

#include "Strategy/ReaderContext.hpp"
#include "Visitor/CellSearchVisitor.hpp"
#include "Visitor/SudokuVisitor.hpp"

Game::Game() : quit_{false}
{
	const std::string path = "resources/puzzle.4x4";
	ReaderContext context;
	sudoku_ = context.read(path);
}

void Game::start()
{
	const auto visitor = new SudokuVisitor();
	searcher_ = new CellSearchVisitor(0, 1);
	sudoku_->accept(searcher_);
	const auto leaf = searcher_->get_cell();
	leaf->set_value(1);
	std::cout << "" << std::endl;

	searcher_->set_target(0, 0);
	sudoku_->accept(searcher_);
	const auto leaf2 = searcher_->get_cell();
	leaf2->set_value(8);
	std::cout << "" << std::endl;
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
