#include "../include/Renderer.hpp"
#include "../include/Game.hpp"

int main(int argc, char* argv[])
{
	const auto game = std::make_shared<Game>();
	Renderer::instance()->init_fields(game);
	game->start();
	Renderer::instance()->start();
	return 0;
}
