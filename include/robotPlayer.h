#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H
#include "../include/player.h"
#include "../include/square.h"

class RobotPlayer:public Player{
public:
	RobotPlayer(int id);	
	RobotPlayer& operator=(const RobotPlayer&);
	bool buyout(Square& square);
		
};

#endif 