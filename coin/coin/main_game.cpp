#include "main_game.h"

Play::Play() {
	flag = true;
	put = false;
	pu = false;
	win = true;
	coin = 50;
	a_coin = 0;
	b_coin = 0;
	a_card = 0;
	b_card = 0;
	count = 0;
}

bool Play::exe() {
	if (put == false) {
		put_coin();
		bet_coin();
	}
	if (put == true) {
		get_coin();
	}
	if (end == true) {
		return true;
	}
}

void Play::put_coin(){
	if (pu == false) {
		board_coin = rnd() % 11 + 5;
		if (board_coin > coin) {
			board_coin = coin;
		}
		pu = true;
	}
	static Font hoge(20);
	hoge(board_coin, L"が出たよ").draw();
}

void Play::bet_coin() {
	static Font hoge(20);

	if (flag == true) {
		hoge(L"Aの入力ターンです").draw(200,200);
		if (Input::Key1.clicked) {
			a_coin = 1;
			flag = false;
			count++;
		}
		if (Input::Key2.clicked) {
			a_coin = 2;
			flag = false;
			count++;
		}
		if (Input::Key3.clicked) {
			a_coin = 3;
			flag = false;
			count++;
		}
		if (Input::Key4.clicked) {
			a_coin = 4;
			flag = false;
			count++;
		}
		if (Input::Key5.clicked) {
			a_card = 5;
			flag = false;
			count++;
		}
		if (Input::Key6.clicked) {
			a_coin = 6;
			flag = false;
			count++;
		}
		if (Input::Key7.clicked) {
			a_coin = 7;
			flag = false;
			count++;
		}
		if (Input::Key8.clicked) {
			a_coin = 8;
			flag = false;
			count++;
		}
		if (Input::Key9.clicked) {
			a_coin = 9;
			flag = false;
			count++;
		}
		
	}
	else {
		hoge(L"Bの入力ターンです").draw(200,200);
		if (Input::Key1.clicked) {
			b_coin = 1;
			flag = true;
			count++;
		}
		if (Input::Key2.clicked) {
			b_coin = 2;
			flag = true;
			count++;
		}
		if (Input::Key3.clicked) {
			b_coin = 3;
			flag = true;
			count++;
		}
		if (Input::Key4.clicked) {
			b_coin = 4;
			flag = true;
			count++;
		}
		if (Input::Key5.clicked) {
			b_coin = 5;
			flag = true;
			count++;
		}
		if (Input::Key6.clicked) {
			b_coin = 6;
			flag = true;
			count++;
		}
		if (Input::Key7.clicked) {
			b_coin = 7;
			flag = true;
			count++;
		}
		if (Input::Key8.clicked) {
			b_coin = 8;
			flag = true;
			count++;
		}
		if (Input::Key9.clicked) {
			b_coin = 9;
			flag = true;
			count++;
		}
	}

	if (count == 2) {
		put = true;
	}
	hoge(a_coin).draw(0, 100);
	hoge(b_coin).draw(0, 200);
}

void Play::get_coin() {
	static Font hoge(20);
	if (win == true) {
		if (a_coin < b_coin) {
			b_card += board_coin;
		}
		else if (a_coin > b_coin) {
			a_card += board_coin;
		}
		coin -= board_coin;
		if (coin == 0) {
			end = true;
		}
		win = false;
	}
	hoge(L"Aのコイン", a_card, L"枚").draw(200,300);
	hoge(L"Bのコイン", b_card, L"枚").draw(200, 350);
	if (Input::KeyEnter.clicked) {
		put = false;
		pu = false;
		win = true;
		check = true;
		count = 0;
	}
}

void Play::set_card() {

}

void Play::result() {
	static Font hoge(20);
	hoge(L"Aのコイン", a_card, L"枚").draw(200, 300);
	hoge(L"Bのコイン", b_card, L"枚").draw(200, 350);
	if (a_card < b_card) {
		hoge(L"Bの勝ち=D").draw(200, 400);
	}
	else if (a_card > b_card) {
		hoge(L"Aの勝ち=D").draw(200, 400);
	}
	else {
		hoge(L"引き分け=D").draw(200, 400);
	}
}