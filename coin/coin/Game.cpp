#include "Game.h"

Game::Game() {
	state = TYTLE;
}

void Game::update() {
	switch (state) {
	case TYTLE:
		if (Input::KeySpace.clicked) {
			state = GAME;
		}
		break;
		
	case GAME:
		play.exe();
		break;

	case RESULT:
		if (Input::KeySpace.clicked) {
			state = TYTLE;
		}
		break;
	}
}

void Game::draw() {
	static Font font(50);
	static Font push(20);
	switch (state) {
	case TYTLE:
		font(L"たいとる未定").drawCenter(350, 250);
		push(L"スペースキーでスタート").drawCenter(350, 350);
		break;
	case GAME:
		break;

	case RESULT:
		font(L"けっかはっぴょー").draw();
		play.result();
		break;
	}
}