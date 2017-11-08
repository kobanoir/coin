#include "Game.h"

void Main(){

	Window::Resize(1260, 980);

	Game game;

	while (System::Update())
	{
		game.update();
		game.draw();
	}
}
