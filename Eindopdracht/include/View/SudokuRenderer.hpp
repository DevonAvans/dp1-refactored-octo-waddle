#pragma once
#include <SDL_ttf.h>

#include "Visitor/SudokuVisitor.hpp"

class SudokuRenderer : public SudokuVisitor
{
public:
	SudokuRenderer(TTF_Font* font);

	void visit_leaf(Leaf* leaf) override;
	void visit_composite(Composite* composite) override;
};
