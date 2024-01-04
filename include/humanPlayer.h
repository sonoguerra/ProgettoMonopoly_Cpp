#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "../include/player.h"
#include "../include/square.h"

class humanPlayer:public player{
public:
	humanPlayer();	
	humanPlayer& operator=(const humanPlayer&);
	bool buyout(Square& square);
	
};

#endif 