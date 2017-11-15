#include "main_game.h"

Play::Play() {
	coin = 50;
	a_coin = 0;
	b_coin = 0;
}

void Play::exe() {
	put_coin();
}

void Play::put_coin(){
	static int test = rnd() % 11 + 5;
	static Font hoge(20);
	hoge(test, L"Ç™èoÇΩÇÊ").draw();
}

void Play::bet_coin() {

}

void Play::get_coin() {

}

void Play::set_card() {

}