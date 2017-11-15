#pragma once
#include "main_game.h"
#include "common.h"

class Game {
public:
	enum State
	{
		TYTLE,
		GAME,
		RESULT,
	};

	Game();
	void update();
	void draw();

private:
	State state;
	Play play;
};