#include "View/Renderer.hpp"
#include "Game.hpp"

int main(int argc, char* argv[])
{
	Renderer::instance()->init_game();
	Renderer::instance()->start();
	return 0;
}
