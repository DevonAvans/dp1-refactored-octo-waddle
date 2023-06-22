#include "../include/Renderer.hpp"

#include <iostream>

#include "../include/Game.hpp"

Renderer::Renderer()
	: window_{},
	  renderer_{},
	  quit_{false}
{
}

Renderer::~Renderer() = default;

void Renderer::init_fields(const std::shared_ptr<Game>& game)
{
	game_ = game;
}

void Renderer::start()
{
	initialize();
}

void Renderer::render()
{
	SDL_Event evt;
	while (!quit_)
	{
		SDL_RenderClear(renderer_);

		while (SDL_PollEvent(&evt) != 0)
		{
			int x, y;
			switch (evt.type)
			{
			case SDL_QUIT:
				quit_ = false;
				close();
				break;
			case SDL_KEYDOWN:
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
			default: ;
			}
		}

		SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);

		SDL_RenderPresent(renderer_);
	}
}

void Renderer::close()
{
	quit_ = true;
	game_->stop();
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}

int Renderer::initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Could not initialize SDL graphics." << std::endl;
		return 1;
	}

	window_ = SDL_CreateWindow("Hallo",
	                           SDL_WINDOWPOS_UNDEFINED,
	                           SDL_WINDOWPOS_UNDEFINED,
	                           screen_width,
	                           screen_height,
	                           0);

	if (!window_)
	{
		std::cout << "Could not create the window." << std::endl;
		std::cout << SDL_GetError() << std::endl;
		close();
		return 2;
	}

	renderer_ = SDL_CreateRenderer(window_,
	                               -1,
	                               SDL_RENDERER_ACCELERATED);

	if (!renderer_)
	{
		std::cout << "Could not create the renderer." << std::endl;
		std::cout << SDL_GetError() << std::endl;
		close();
		return 3;
	}

	if (TTF_Init() < 0)
	{
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
		close();
	}

	/*font_ = TTF_OpenFont("resources/Roboto-Regular.ttf", 12);
	if (!font_)
	{
		std::cout << "Could not open font!";
		close();
	}*/

	render();
	return 0;
}
