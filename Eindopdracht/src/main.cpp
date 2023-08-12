#include "View/Renderer.hpp"
#include "Game.hpp"

int main(int argc, char* argv[])
{
	const std::string path = "resources/puzzle.4x4";

	Renderer::instance()->init_game(path);
	Renderer::instance()->start();
	return 0;
}
