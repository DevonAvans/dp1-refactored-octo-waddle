#include "View/BoardRendererVisitor.hpp"

#include <SDL_render.h>
#include <SDL_ttf.h>
#include <string>

#include "View/Color.hpp"

BoardRendererVisitor::BoardRendererVisitor(const int cell_size, SDL_Renderer* renderer, TTF_Font* font,
                                           TTF_Font* small_font)
	: cell_size_{cell_size},
	  renderer_{renderer},
	  normal_font_{font},
	  small_font_{small_font},
	  dictionairy_{
		  Color::red(),
		  Color::blue(),
		  Color::orange(),
		  Color::cyan(),
		  Color::magenta(),
		  Color::pink(),
		  Color::purple(),
		  Color::yellow(),
		  Color::brown()
	  }
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
	const auto [row, col, section, sudoku] = leaf->get_attributes();
	const auto x = col * cell_size_;
	const auto y = row * cell_size_;
	const auto value = leaf->get_value();
	const auto candidates = leaf->get_candidates();

	// Set border color
	//const auto& [br, bg, bb, ba] = Color::to_sdl(Color::black());
	//SDL_SetRenderDrawColor(renderer_, br, bg, bb, ba);

	//// Draw black border
	//const SDL_Rect border_rect = {x, y, cell_size_, cell_size_};
	//SDL_RenderFillRect(renderer_, &border_rect);

	// Set white background color
	const auto& [wr, wg, wb, wa] = Color::to_sdl(Color::white());
	SDL_SetRenderDrawColor(renderer_, wr, wg, wb, wa);

	// Set inner color
	const auto& inner_color = dictionairy_[section];
	const auto& [r, g, b, a] = Color::to_sdl(inner_color);
	SDL_SetRenderDrawColor(renderer_, r, g, b, 100);

	const auto border_size = 1;
	// Draw inner white rectangle
	const SDL_Rect inner_rect = {
		x + border_size, y + border_size, cell_size_ - 2 * border_size, cell_size_ - 2 * border_size
	};
	SDL_RenderFillRect(renderer_, &inner_rect);

	if (value != 0)
	{
		const SDL_Color text_color = Color::to_sdl(Color::black());
		SDL_Surface* text_surface = TTF_RenderText_Solid(normal_font_, std::to_string(value).c_str(), text_color);
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
	else if (!candidates.empty())
	{
		const SDL_Color text_color = {33, 33, 33, 200};

		// Calculate the position for each candidate number
		const int candidate_width = cell_size_ / 3;
		const int candidate_height = cell_size_ / 3;

		int candidate_x = x;
		int candidate_y = y;

		const int max_candidates_per_row = 3;
		int candidates_in_current_row = 0;

		for (const auto& candidate : candidates)
		{
			SDL_Surface* text_surface =
				TTF_RenderText_Solid(small_font_, std::to_string(candidate).c_str(), text_color);
			SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer_, text_surface);

			const int text_width = text_surface->w;
			const int text_height = text_surface->h;

			const SDL_Rect text_rect = {
				candidate_x + (candidate_width - text_width) / 2,
				candidate_y + (candidate_height - text_height) / 2,
				text_width,
				text_height
			};

			SDL_RenderCopy(renderer_, text_texture, nullptr, &text_rect);

			SDL_DestroyTexture(text_texture);
			SDL_FreeSurface(text_surface);

			candidates_in_current_row++;
			candidate_x += candidate_width;

			if (candidates_in_current_row >= max_candidates_per_row)
			{
				candidates_in_current_row = 0;
				candidate_x = x;
				candidate_y += candidate_height;
			}
		}
	}
}
