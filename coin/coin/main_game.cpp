#include "main_game.h"

Play::Play() {
	flag = true;
	pu = false;
	win = true;
	phase = Display;
	coin = 51;
	a_coin = 0;
	b_coin = 0;
	a_card = 0;
	b_card = 0;
	count = 0;
	round = 1;
}

void Play::exe() {
	switch (phase) {
	case Display:
		put_coin();
		draw_board();
		break;
	case Bet:
		bet_coin();
		draw_board();
		break;
	case Check:
		get_coin();
		draw_board();
		break;
	case Reset:
		set_card();
		break;
	case Result:
		result();
		break;
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
	phase = Bet;
}

void Play::bet_coin() {
	static Font hoge(20);
	if (flag == true) {
		hoge(L"Aの入力ターンです").draw(200,200);
		if (Input::Key1.clicked && card[0][0] == false) {
			a_coin = 1;
			flag = false;
			count++;
		}
		if (Input::Key2.clicked && card[0][1] == false) {
			a_coin = 2;
			flag = false;
			count++;
		}
		if (Input::Key3.clicked && card[0][2] == false) {
			a_coin = 3;
			flag = false;
			count++;
		}
		if (Input::Key4.clicked && card[0][3] == false) {
			a_coin = 4;
			flag = false;
			count++;
		}
		if (Input::Key5.clicked && card[0][4] == false) {
			a_coin = 5;
			flag = false;
			count++;
		}
		if (Input::Key6.clicked && card[0][5] == false) {
			a_coin = 6;
			flag = false;
			count++;
		}
		if (Input::Key7.clicked && card[0][6] == false) {
			a_coin = 7;
			flag = false;
			count++;
		}
		if (Input::Key8.clicked && card[0][7] == false) {
			a_coin = 8;
			flag = false;
			count++;
		}
		if (Input::Key9.clicked && card[0][8] == false) {
			a_coin = 9;
			flag = false;
			count++;
		}
		
	}
	else {
		hoge(L"Bの入力ターンです").draw(200,200);
		if (Input::Key1.clicked && card[1][0] == false) {
			b_coin = 1;
			flag = true;
			count++;
		}
		if (Input::Key2.clicked && card[1][1] == false) {
			b_coin = 2;
			flag = true;
			count++;
		}
		if (Input::Key3.clicked && card[1][2] == false) {
			b_coin = 3;
			flag = true;
			count++;
		}
		if (Input::Key4.clicked && card[1][3] == false) {
			b_coin = 4;
			flag = true;
			count++;
		}
		if (Input::Key5.clicked && card[1][4] == false) {
			b_coin = 5;
			flag = true;
			count++;
		}
		if (Input::Key6.clicked && card[1][5] == false) {
			b_coin = 6;
			flag = true;
			count++;
		}
		if (Input::Key7.clicked && card[1][6] == false) {
			b_coin = 7;
			flag = true;
			count++;
		}
		if (Input::Key8.clicked && card[1][7] == false) {
			b_coin = 8;
			flag = true;
			count++;
		}
		if (Input::Key9.clicked && card[1][8] == false) {
			b_coin = 9;
			flag = true;
			count++;
		}
	}

	if (count == 2) {
		phase = Check;
	}
}

void Play::get_coin() {
	static Font hoge(20);
	static Font fuga(25);
	if (win == true) {
		if (a_coin < b_coin) {
			b_card += board_coin;
		}
		else if (a_coin > b_coin) {
			a_card += board_coin;
		}
		coin -= board_coin;
		if (coin == 0) {
			phase = Result;
		}
		card[0][a_coin - 1] = true;
		card[1][b_coin - 1] = true;
		win = false;
	}
	hoge(L"Aの選択カード",a_coin).drawCenter(363,175);
	hoge(L"Bの選択カード",b_coin).drawCenter(363,275);
	if (a_coin < b_coin) {
		hoge(L"このラウンドのコインはBが獲得しました").drawCenter(363, 375);
	}
	else if (a_coin > b_coin) {
		hoge(L"このラウンドのコインはAが獲得しました").drawCenter(363, 375);
	}
	else {
		hoge(L"このラウンドは引き分けです").drawCenter(363, 375);
	}
	if (Input::KeyEnter.clicked) {
		pu = false;
		win = true;
		check = true;
		count = 0;
		if (round % 9 == 0) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 9; j++) {
					card[i][j] = false;
				}
			}
			phase = Display;
		}
		else {
			phase = Display;
		}
		round++;
	}
}

void Play::set_card() {
	flag = true;
	pu = false;
	win = true;
	phase = Display;
	coin = 50;
	a_coin = 0;
	b_coin = 0;
	a_card = 0;
	b_card = 0;
	count = 0;
	round = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 9; j++) {
			card[i][j] = false;
		}
	}
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
	hoge(L"Enterキーで次のゲームへ");
	if (Input::KeyEnter.clicked) {
		phase = Reset;
	}
}

void Play::draw_board() {
	static Font hoge(20);
	hoge(L"残りコイン ", coin).draw(0, 400);
	hoge(L"Aの所持コイン", a_card, L"枚").draw(0, 450);
	hoge(L"Bの所持コイン", b_card, L"枚").draw(0, 500);
	hoge(L"このラウンドの賭けコインx", board_coin).draw(0,50);
	hoge(round, L"ラウンド").draw();
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 9; i++) {
			if (card[j][i] == true) {
				Line(500 + i * 25, j * 500, 500 + i * 25 + 20, j * 500 + 35).draw(3,Palette::Red);
				Line(500 + i * 25 + 20, j * 500, 500 + i * 25, j * 500 + 35).draw(3,Palette::Red);
			}
			hoge(i + 1).draw(500 + i * 25,j * 500);
		}
	}
}