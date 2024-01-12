#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H
#include "../include/player.h"
#include "../include/square.h"

class RobotPlayer:public Player{
public:
	RobotPlayer();
	RobotPlayer(int id);	
	RobotPlayer(const RobotPlayer& r);
	bool buyout(Square& square);
		
};

#endif 