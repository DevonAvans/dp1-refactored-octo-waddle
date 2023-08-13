#pragma once
#include <string>

#include "Command.hpp"

class Game;

class LoadPuzzle final : public Command
{
public:
	explicit LoadPuzzle(Game& game);

	void execute() const override;
protected:
	const std::string path_ = "resources/puzzle.4x4";
private:
	Game& game_;
};
