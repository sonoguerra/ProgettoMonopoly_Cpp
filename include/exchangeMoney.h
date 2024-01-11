#ifndef EXCHANGEMONEY_H
#define EXCHANGEMONEY_H
#include "../include/player.h"
#include "../include/square.h"
#include <fstream>

namespace exchangeMoney{
	
	int passing_cost(const Square& square);
	int building_cost(const Square& square);	
	int buying_price(const Square& square);	
	bool pay_someone(Player& p1,Player& p2,const Square& square);
	void passing_prize(Player& p1);
	std::ofstream scrittura;

	
};
#endif 