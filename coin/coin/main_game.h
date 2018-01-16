#pragma once
#include "common.h"

class Play {
public:
	Play();
	enum Phase
	{
		Display,
		Bet,
		Check,
		Reset,
		Result,
	};
	void exe();
	void put_coin();
	void bet_coin();
	void get_coin();
	void set_card();
	void draw_board();
	void result();
private:
	bool card[2][9] = {false};
	Phase phase;
	bool flag;
	bool pu;
	bool win;
	bool check;
	int round;
	int count;
	int coin;
	int board_coin;
	int a_coin;
	int b_coin;
	int a_card;
	int b_card;
	random_device rnd;
};