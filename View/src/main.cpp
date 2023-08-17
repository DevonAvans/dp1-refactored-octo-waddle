#include <iostream>

#include "Renderer.hpp"
#include "Game.hpp"
#include "Util.hpp"

int main(int argc, char* argv[])
{
	const std::string path = "resources/puzzle.samurai";

	try
	{
		int res = utils::safe_stoi("12a3");
		Renderer::instance()->init_game(path);
		Renderer::instance()->start();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
