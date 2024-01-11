#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H
#include "../include/player.h"
#include "../include/square.h"

class RobotPlayer:public Player{
public:
	RobotPlayer();
	RobotPlayer(int id);	
	RobotPlayer(const RobotPlayer& rb);	
	RobotPlayer& operator=(const RobotPlayer& rb);		
	bool buyout(Square& square);	
	bool build_house(Square& square);
	bool build_hotel(Square& square);
	
	
};

#endif 