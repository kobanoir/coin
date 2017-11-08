#pragma once
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
};