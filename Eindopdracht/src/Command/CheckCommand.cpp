#include "Command/CheckCommand.hpp"

#include "Game.hpp"

CheckCommand::CheckCommand(Game& game): game_{game}
{
}

void CheckCommand::execute() const
{
	game_.check();
}
