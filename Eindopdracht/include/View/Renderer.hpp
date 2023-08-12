#pragma once

#include <memory>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <thread>

#include "Vector2.h"

class Leaf;
class BoardRendererVisitor;
class Game;

constexpr int SCREEN_WIDTH = 900;
constexpr int SCREEN_HEIGHT = 900;

constexpr int CELL_SIZE = 40;

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

	void init_game(const std::string& path);
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
	std::unique_ptr<BoardRendererVisitor> drawer_;
	bool quit_;

	void draw() const;
	void draw_highlight() const;

	[[nodiscard]] int initialize();
};
