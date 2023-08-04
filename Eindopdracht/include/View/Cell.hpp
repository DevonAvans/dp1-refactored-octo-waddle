#pragma once

#include "Renderable.hpp"
#include "Composite/Leaf.hpp"

class Cell : public Renderable
{
public:
	explicit Cell(std::shared_ptr<Leaf>& leaf);

	void render(SDL_Renderer* renderer, TTF_Font* font) const override;

private:
	std::shared_ptr<Leaf>& cell_;
};
