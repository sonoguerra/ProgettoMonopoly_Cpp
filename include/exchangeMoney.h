#ifndef EXCHANGEMONEY_H
#define EXCHANGEMONEY_H
#include "../include/player.h"
#include "../include/square.h"

class exchangeMoney{
public:
	exchangeMoney();
	static int square_value(const Square& square);
	static int building_cost(const Square& square);	
	static int square_price(const Square& square);	
	static void pay_someone(player& p1,player& p2,const Square& square);
	static void passing_prize(player& p1);
	


	
};
#endif 