#include "Command/LoadPuzzle.hpp"

#include "Game.hpp"

LoadPuzzle::LoadPuzzle(Game& game) : game_{game}
{
}

void LoadPuzzle::execute() const
{
	game_.start(path_);
}
