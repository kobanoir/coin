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
		if (Input::KeySpace.clicked) {
			state = RESULT;
		}
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
		font(L"�����Ƃ関��").drawCenter(630, 320);
		push(L"�X�y�[�X�L�[�ŃX�^�[�g").drawCenter(630, 640);
		break;
	case GAME:
		break;

	case RESULT:
		font(L"�������͂��҂�[").draw();
		break;
	}
}