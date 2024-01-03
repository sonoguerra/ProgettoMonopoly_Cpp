#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H
#include "../include/player.h"
#include "../include/square.h"

class robotPlayer:public player{
public:
	robotPlayer(int id);	
	robotPlayer& operator=(const robotPlayer&);
	bool buyout(Square& square);
		
};

#endif 