#pragma once
#include "Command.hpp"

class Game;

class CheckCommand final : public Command
{
public:
	explicit CheckCommand(Game& game);

	void execute() const override;

private:
	Game& game_;
};
