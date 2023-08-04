#include "View/Renderer.hpp"

#include <iostream>

#include "Game.hpp"
#include "View/Color.hpp"
#include "Composite/Composite.hpp"
#include "View/Cell.hpp"

const int SIZE = 4;

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
	auto status = initialize();
}

void Renderer::render()
{
	SDL_Event evt;
	while (!quit_)
	{
		while (SDL_WaitEvent(&evt))
		{
			int x, y;
			switch (evt.type)
			{
			case SDL_QUIT:
				quit_ = true;
				close();
				break;
			case SDL_KEYDOWN:
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (evt.button.button)
				{
				case SDL_BUTTON_LEFT:
					x = evt.button.x;
					y = evt.button.y;

					hightlight_square({x, y});
					break;
				default: ;
				}
				break;
			default: ;
			}

			SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
			SDL_RenderClear(renderer_);

			draw_normal_board();
			/*
			if (square_.x >= 0)
				draw_highlighted_square();
			draw_highlighted_row();
			*/

			SDL_RenderPresent(renderer_);
		}
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

void Renderer::hightlight_square(const Vector2 pos)
{
	const auto [x, y] = pos;

	const int row = pos.y / CELL_SIZE;
	const int col = pos.x / CELL_SIZE;

	auto aaa = game_->get_sudoku();

	if (row > SIZE - 1 || col > SIZE - 1)
	{
		square_.x = -1;
		square_.y = -1;
	}
	else
	{
		const int squareX = col * CELL_SIZE;
		const int squareY = row * CELL_SIZE;

		square_.x = squareX;
		square_.y = squareY;
	}
}

void Renderer::draw_highlighted_square() const
{
	const auto& [r, g, b, a] = Color::to_sdl(Color::yellow());
	SDL_SetRenderDrawColor(renderer_, r, g, b, a);
	const SDL_Rect rect{square_.x, square_.y, CELL_SIZE, CELL_SIZE};
	SDL_RenderFillRect(renderer_, &rect);
}

void Renderer::draw_highlighted_row() const
{
	const auto& [r, g, b, a] = Color::to_sdl(Color::red());
	SDL_SetRenderDrawColor(renderer_, r, g, b, a);
	const SDL_Rect rect{0, square_.y, SIZE * CELL_SIZE + 1, CELL_SIZE};
	SDL_RenderDrawRect(renderer_, &rect);
}

void Renderer::draw_highlighted_col() const
{
	/*SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 255);
	const SDL_Rect rect{square_.x, 0, CELL_SIZE, game_->get_board_size() * CELL_SIZE};
	SDL_RenderDrawRect(renderer_, &rect);*/
}

void Renderer::draw_highlighted_collection() const
{
}

void Renderer::draw_normal_board() const
{
	const std::shared_ptr<Component> sudoku = game_->get_sudoku();
	// TODO: get values of sudoku
	const int board_size = SIZE;
	const int grid_size = board_size * CELL_SIZE;
	//auto leaf = std::make_shared<Leaf>(5);
	//Cell cell{leaf};
	//cell.render(renderer_, font_);

	/*SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);

	for (int i = 0; i <= grid_size; i += CELL_SIZE)
	{
		SDL_RenderDrawLine(renderer_, 0 + i, 0, 0 + i, 0 + grid_size);
	}

	for (int i = 0; i <= grid_size; i += CELL_SIZE)
	{
		SDL_RenderDrawLine(renderer_, 0, 0 + i, 0 + grid_size, 0 + i);
	}

	SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);

	for (int i = 0; i <= grid_size; i += static_cast<int>(sqrt(board_size)) * CELL_SIZE)
	{
		SDL_RenderDrawLine(renderer_, 0 + i, 0, 0 + i, 0 + grid_size);
	}

	for (int i = 0; i <= grid_size; i += static_cast<int>(sqrt(board_size)) * CELL_SIZE)
	{
		SDL_RenderDrawLine(renderer_, 0, 0 + i, 0 + grid_size, 0 + i);
	}*/
}

void Renderer::draw_samurai_board() const
{
}

void Renderer::find_square(const Vector2 pos) const
{
	int row = pos.y / CELL_SIZE;
	int col = pos.x / CELL_SIZE;
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
	                           SCREEN_WIDTH,
	                           SCREEN_HEIGHT,
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

	font_ = TTF_OpenFont("resources/fonts/Roboto-Regular.ttf", 12);
	if (!font_)
	{
		std::cout << "Could not open font!";
		close();
	}

	render();
	return 0;
}
