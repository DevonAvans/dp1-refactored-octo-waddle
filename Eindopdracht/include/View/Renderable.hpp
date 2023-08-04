#pragma once
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "Vector2.h"

class Renderable
{
public:
	virtual void render(SDL_Renderer* renderer, TTF_Font* font) const = 0;

protected:
	Vector2 pos_ = {};
};
