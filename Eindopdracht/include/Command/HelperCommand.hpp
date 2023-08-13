#pragma once
#include "Command.hpp"

class Game;

class HelperCommand final : public Command
{
public:
	explicit HelperCommand(Game& game);

	void execute() const override;

private:
	Game& game_;
};
