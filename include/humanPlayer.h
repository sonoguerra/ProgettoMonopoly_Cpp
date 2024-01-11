#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "../include/player.h"
#include "../include/square.h"

class HumanPlayer:public Player{
public:
	HumanPlayer();
	HumanPlayer(int id);
	HumanPlayer(const HumanPlayer& hp);	
	HumanPlayer& operator=(const HumanPlayer& hp);	
	bool buyout(Square& square);
	bool build_house(Square& square);
	bool build_hotel(Square& square);
	
	
};

#endif 