#include "Game.h"

void Main(){

	Window::Resize(725, 550);

	Game game;

	while (System::Update())
	{
		game.update();
		game.draw();
	}
}
