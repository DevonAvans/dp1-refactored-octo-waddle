#include "Command/HelperCommand.hpp"

#include <memory>

#include "Game.hpp"
#include "State/Game/HelperGameState.hpp"

HelperCommand::HelperCommand(Game& game): game_{game}
{
}

void HelperCommand::execute() const
{
	game_.set_game_state(std::make_unique<HelperGameState>());
}
