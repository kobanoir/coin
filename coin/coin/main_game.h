#pragma once
#include "common.h"

class Play {
public:
	Play();
	void exe();
	void put_coin();
	void bet_coin();
	void get_coin();
	void set_card();
private:
	int coin;
	int a_coin;
	int b_coin;
	int a_card;
	int b_card;
	random_device rnd;
};