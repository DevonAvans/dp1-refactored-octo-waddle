#pragma once
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "Visitor/Visitor.hpp"

class Color;

class BoardRendererVisitor final : public Visitor
{
public:
	explicit BoardRendererVisitor(int cell_size, SDL_Renderer* renderer, TTF_Font* font);

	void render_sudoku(const std::shared_ptr<Component>& sudoku);

	void visit_leaf(Leaf* leaf) override;
	void visit_composite(Composite* composite) override;

private:
	int cell_size_;
	SDL_Renderer* renderer_;
	TTF_Font* font_;

	std::vector<Color> dictionairy_;

	void draw(const Leaf* leaf);
};
