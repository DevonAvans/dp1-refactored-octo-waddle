#pragma once
#include "Command.hpp"

class Game;

class DefinitiveCommand final : public Command
{
public:
	explicit DefinitiveCommand(Game& game);

	void execute() const override;

private:
	Game& game_;
};
