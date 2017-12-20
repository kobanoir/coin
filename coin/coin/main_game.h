#pragma once
#include "common.h"

class Play {
public:
	Play();
	bool exe();
	void put_coin();
	void bet_coin();
	void get_coin();
	void set_card();
	void result();
private:
	bool flag;
	bool put;
	bool pu;
	bool win;
	bool check;
	bool end;
	int count;
	int coin;
	int board_coin;
	int a_coin;
	int b_coin;
	int a_card;
	int b_card;
	random_device rnd;
};