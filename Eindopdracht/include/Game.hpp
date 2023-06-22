#pragma once

class Game
{
public:
	explicit Game();
	void start();
	void update();
	void stop();

private:
	bool quit_;
};
