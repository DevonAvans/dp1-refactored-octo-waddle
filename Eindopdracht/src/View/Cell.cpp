#include "View/Cell.hpp"
#include <SDL.h>
#include <string>

#include "View/Renderer.hpp"

Cell::Cell(std::shared_ptr<Leaf>& cell) : cell_{cell}
{
}

void Cell::render(SDL_Renderer* renderer, TTF_Font* font) const
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	const SDL_Rect rect{0, 0, 50, 50};
	SDL_RenderFillRect(renderer, &rect);

	SDL_Color text_color = {0, 0, 0, 255};
	SDL_Surface* surface;
	SDL_Texture* texture;

	surface = TTF_RenderText_Blended(font, std::to_string(cell_->get_value()).c_str(), text_color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect dest = {25, 25, surface->w, surface->h};
	SDL_RenderCopy(renderer, texture, nullptr, &dest);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
