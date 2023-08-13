#include "Command/DefinitiveCommand.hpp"

#include <memory>

#include "Game.hpp"
#include "State/Game/DefinitiveGameState.hpp"

DefinitiveCommand::DefinitiveCommand(Game& game): game_{game}
{
}

void DefinitiveCommand::execute() const
{
	game_.set_game_state(std::make_unique<DefinitiveGameState>());
}
