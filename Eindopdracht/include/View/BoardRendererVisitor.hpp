#pragma once
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "Visitor/Visitor.hpp"

class Color;

class BoardRendererVisitor final : public Visitor
{
public:
	explicit BoardRendererVisitor(int cell_size, SDL_Renderer* renderer, TTF_Font* font, TTF_Font* small_font);

	void render_sudoku(const std::shared_ptr<Component>& sudoku);

	void visit_leaf(Leaf* leaf) override;
	void visit_composite(Composite* composite) override;

private:
	int cell_size_;
	SDL_Renderer* renderer_;
	TTF_Font* normal_font_;
	TTF_Font* small_font_;

	std::vector<Color> dictionairy_;

	void draw(const Leaf* leaf) const;
	int calc_x(int col, int sudoku) const;
	int calc_y(int row, int sudoku) const;
};
