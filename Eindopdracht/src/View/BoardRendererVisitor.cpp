#include "View/BoardRendererVisitor.hpp"

#include <SDL_render.h>
#include <SDL_ttf.h>
#include <string>

#include "View/Color.hpp"

BoardRendererVisitor::BoardRendererVisitor(const int cell_size, SDL_Renderer* renderer, TTF_Font* font)
	: cell_size_{cell_size},
	  renderer_{renderer},
	  font_{font}
{
}

void BoardRendererVisitor::render_sudoku(const std::shared_ptr<Component>& sudoku)
{
	sudoku->accept(this);
}

void BoardRendererVisitor::visit_leaf(Leaf* leaf)
{
	draw(leaf);
}

void BoardRendererVisitor::visit_composite(Composite* composite)
{
	for (const auto& child : composite->get_children())
	{
		child->accept(this);
	}
}

void BoardRendererVisitor::draw(const Leaf* leaf) const
{
	const auto x = leaf->get_col() * cell_size_;
	const auto y = leaf->get_row() * cell_size_;
	const auto value = leaf->get_value();


	// Set border color
	const auto& [br, bg, bb, ba] = Color::to_sdl(Color::black());
	SDL_SetRenderDrawColor(renderer_, br, bg, bb, ba);

	// Draw black border
	const SDL_Rect border_rect = {x, y, cell_size_, cell_size_};
	SDL_RenderFillRect(renderer_, &border_rect);

	// Set inner color
	const auto& [wr, wg, wb, wa] = Color::to_sdl(Color::white());
	SDL_SetRenderDrawColor(renderer_, wr, wg, wb, wa);

	const auto border_size = 1;
	// Draw inner white rectangle
	const SDL_Rect inner_rect = {
		x + border_size, y + border_size, cell_size_ - 2 * border_size, cell_size_ - 2 * border_size
	};
	SDL_RenderFillRect(renderer_, &inner_rect);

	if (value != 0)
	{
		const SDL_Color text_color = {0, 0, 0, 255}; // Black text color
		SDL_Surface* text_surface = TTF_RenderText_Solid(font_, std::to_string(value).c_str(), text_color);
		SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer_, text_surface);

		const int text_width = text_surface->w;
		const int text_height = text_surface->h;

		const SDL_Rect text_rect = {
			x + (cell_size_ - text_width) / 2,
			y + (cell_size_ - text_height) / 2,
			text_width,
			text_height
		};

		SDL_RenderCopy(renderer_, text_texture, nullptr, &text_rect);

		SDL_DestroyTexture(text_texture);
		SDL_FreeSurface(text_surface);
	}
}
