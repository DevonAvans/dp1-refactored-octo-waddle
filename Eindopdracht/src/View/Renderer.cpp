#include "View/Renderer.hpp"

#include <iostream>

#include "Game.hpp"
#include "State/Game/DefinitiveGameState.hpp"
#include "View/Color.hpp"
#include "View/BoardRendererVisitor.hpp"

Renderer::Renderer()
	: window_{},
	  renderer_{},
	  quit_{false}
{
}

Renderer::~Renderer() = default;

void Renderer::init_game(const std::string& path)
{
	try
	{
		game_ = std::make_unique<Game>(path, std::make_unique<DefinitiveGameState>());
	}
	catch (const std::runtime_error& e)
	{
		throw e;
	}
}

void Renderer::start()
{
	if (initialize())
	{
		throw std::runtime_error("Renderer init went wrong");
	}
	drawer_ = std::make_unique<BoardRendererVisitor>(CELL_SIZE, renderer_, normal_font_, smal_font_);
	render();
}

void Renderer::render()
{
	SDL_Event evt;

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
				if (evt.key.keysym.sym == SDLK_c)
				{
					game_->execute_command(key::Check);
				}
				else if (evt.key.keysym.sym == SDLK_d)
				{
					game_->execute_command(key::Definitive);
				}
				else if (evt.key.keysym.sym == SDLK_h)
				{
					game_->execute_command(key::Helper);
				}
				else if (evt.key.keysym.sym == SDLK_l)
				{
					game_->execute_command(key::LoadPuzzle);
				}
				if (game_->get_searcher_target() != nullptr)
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
						game_->set_cell_value(*game_->get_searcher_target(), input_value);
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
					break;
				default: ;
				}
				break;
			default: ;
			}

			SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
			SDL_RenderClear(renderer_);

			draw();
			draw_highlight();

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

void Renderer::draw() const
{
	const std::shared_ptr<Component> sudoku = game_->get_sudoku();
	drawer_->render_sudoku(sudoku);
}

void Renderer::draw_highlight() const
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

int Renderer::initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Could not initialize SDL graphics." << std::endl;
		return 1;
	}

	window_ = SDL_CreateWindow("Design Patterns 1",
	                           SDL_WINDOWPOS_UNDEFINED,
	                           SDL_WINDOWPOS_UNDEFINED,
	                           SCREEN_WIDTH,
	                           SCREEN_HEIGHT,
	                           SDL_WINDOW_RESIZABLE);

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

	return 0;
}
