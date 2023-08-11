#include "View/Renderer.hpp"

#include <iostream>

#include "Composite/Composite.hpp"
#include "Composite/Leaf.hpp"
#include "Game.hpp"
#include "State/Game/DefinitiveGameState.hpp"
#include "State/Game/HelperGameState.hpp"
#include "View/Color.hpp"
#include "View/BoardRendererVisitor.hpp"

Renderer::Renderer()
	: window_{},
	  renderer_{},
	  quit_{false}
{
}

Renderer::~Renderer() = default;

void Renderer::init_game()
{
	const std::string path = "resources/puzzle.6x6";
	game_ = std::make_shared<Game>(path, std::make_unique<DefinitiveGameState>());
}

void Renderer::start()
{
	auto status = initialize();
	game_->start();
}

void Renderer::render()
{
	SDL_Event evt;
	Leaf* leaf;

	SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);

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
				if (evt.key.keysym.sym == SDLK_d)
				{
					game_->set_game_state(std::make_unique<DefinitiveGameState>());
				}
				else if (evt.key.keysym.sym == SDLK_h)
				{
					game_->set_game_state(std::make_unique<HelperGameState>());
				}
				leaf = game_->get_searcher_target();
				if (leaf != nullptr)
				{
					int input_value = -1; // Initialize with an invalid value

					// Get the key code from the event
					const SDL_Keycode key_code = evt.key.keysym.sym;

					// Check if the key code corresponds to a numeric key (1-9)
					if (key_code >= SDLK_0 && key_code <= SDLK_9)
					{
						input_value = key_code - SDLK_1 + 1; // Convert key code to input value (1-9)
					}

					if (input_value >= 0 && input_value <= 9)
					{
						game_->set_cell_value(*leaf, input_value);
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (evt.button.button)
				{
				case SDL_BUTTON_LEFT:
					x = evt.button.x;
					y = evt.button.y;

					game_->set_searcher_target(y / CELL_SIZE, x / CELL_SIZE);
				//hightlight_square({x, y});
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
			draw_highlighted_square();

			SDL_RenderPresent(renderer_);
			leaf = nullptr;
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

void Renderer::hightlight_square()
{
}

void Renderer::draw_highlighted_square() const
{
	const auto leaf = game_->get_searcher_target();
	if (leaf == nullptr) { return; }

	const auto [row, col, section, sudoku] = leaf->get_attributes();

	const auto& [r, g, b, a] = Color::to_sdl(Color::black());
	SDL_SetRenderDrawColor(renderer_, r, g, b, 100);

	const int selected_x = col * CELL_SIZE;
	const int selected_y = row * CELL_SIZE;

	// Draw a red rectangle over the selected square
	const SDL_Rect selectedRect = {selected_x, selected_y, CELL_SIZE, CELL_SIZE};
	SDL_RenderFillRect(renderer_, &selectedRect);
}

void Renderer::draw_highlighted_row() const
{
	const auto& [r, g, b, a] = Color::to_sdl(Color::red());
	SDL_SetRenderDrawColor(renderer_, r, g, b, a);
	//const SDL_Rect rect{0, square_.y, SIZE * CELL_SIZE + 1, CELL_SIZE};
	//SDL_RenderDrawRect(renderer_, &rect);
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
	BoardRendererVisitor board_r{CELL_SIZE, renderer_, normal_font_, smal_font_};
	board_r.render_sudoku(sudoku);
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

	normal_font_ = TTF_OpenFont("resources/fonts/Roboto-Bold.ttf", 16);
	if (!normal_font_)
	{
		std::cout << "Could not open font!";
		close();
	}

	smal_font_ = TTF_OpenFont("resources/fonts/Roboto-Bold.ttf", 12);
	if (!smal_font_)
	{
		std::cout << "Could not open font!";
		close();
	}

	render();
	return 0;
}
