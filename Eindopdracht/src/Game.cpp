#include "Game.hpp"

#include <iostream>

#include "Strategy/ReaderContext.hpp"
#include "Visitor/CellSearchVisitor.hpp"
#include "Visitor/SudokuVisitor.hpp"

Game::Game() : quit_{false}
{
}

void Game::start()
{
	const std::string path = "resources/puzzle.4x4";
	ReaderContext context;
	sudoku_ = context.read(path);
	const auto visitor = new SudokuVisitor();
	const auto searcher = new CellSearchVisitor(0, 1);
	sudoku_->accept(searcher);
	const auto leaf = searcher->get_cell();
	std::cout << "" << std::endl;
}

void Game::update()
{
	/*
	 *while (!quit_)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit_ = true;
				std::cout << "WINDOW close" << std::endl;
			}
		}
	}
	*/
}

void Game::stop()
{
	quit_ = true;
}

std::shared_ptr<Component> Game::get_sudoku()
{
	return sudoku_;
}
