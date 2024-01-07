#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "../include/player.h"
#include "../include/square.h"

class HumanPlayer:public Player{
public:
	HumanPlayer();	
	HumanPlayer& operator=(const HumanPlayer&);
	bool buyout(Square& square);
	
};

#endif 