#include <iostream>

#include "Renderer.hpp"
#include "Game.hpp"

int main(int argc, char* argv[])
{
	const std::string path = "resources/puzzle.6x6";

	try
	{
		Renderer::instance()->init_game(path);
		Renderer::instance()->start();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
