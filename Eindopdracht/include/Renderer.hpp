#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <memory>
#include <SDL.h>
#include <SDL_ttf.h>
#include <thread>

class Game;

constexpr int screen_width = 800;
constexpr int screen_height = 600;

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

	void init_fields(const std::shared_ptr<Game>& game);
	void init_thread();
	void start();
	void render();
	void close();

private:
	Renderer();
	~Renderer();

	SDL_Window* window_;
	SDL_Renderer* renderer_;
	TTF_Font* font_{};

	std::shared_ptr<int> main_loop_;
	std::unique_ptr<std::thread> thread_;
	std::shared_ptr<Game> game_;
	bool quit_;

	[[nodiscard]] int initialize();
};

#endif // RENDERER_HPP
