#include "Game.hpp"

#include <iostream>

#include "Strategy/ReaderContext.hpp"

Game::Game() : quit_{false}
{
}

void Game::start()
{
	const std::string path = "resources/puzzle.4x4";
	ReaderContext context;
	sudoku_ = context.read(path);
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
