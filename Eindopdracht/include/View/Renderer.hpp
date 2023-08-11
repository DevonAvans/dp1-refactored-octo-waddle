#pragma once

#include <memory>
#include <SDL.h>
#include <SDL_ttf.h>
#include <thread>

#include "Vector2.h"

class Leaf;
class BoardRendererVisitor;
class Game;

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

constexpr int CELL_SIZE = 50;

class Renderer final
{
public:
	static Renderer* instance()
	{
		static Renderer instance;
		return &instance;
	}

	Renderer(const Renderer& other) = delete;
	Renderer(Renderer&& other) noexcept = delete;
	Renderer& operator=(const Renderer& other) = delete;
	Renderer& operator=(Renderer&& other) noexcept = delete;

	void init_game();
	void start();
	void render();
	void close();

private:
	Renderer();
	~Renderer();

	SDL_Window* window_;
	SDL_Renderer* renderer_;
	TTF_Font* normal_font_{};
	TTF_Font* smal_font_{};

	std::shared_ptr<Game> game_;
	bool quit_;

	//Vector2 square_;

	void hightlight_square();
	void draw_highlighted_square() const;

	void draw_highlighted_row() const;
	void draw_highlighted_col() const;
	void draw_highlighted_collection() const;

	void draw_normal_board() const;
	void draw_samurai_board() const;

	void find_square(Vector2 pos) const;

	[[nodiscard]] int initialize();
};
