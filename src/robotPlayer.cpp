#include "../include/robotPlayer.h"

RobotPlayer::RobotPlayer() {}

RobotPlayer::RobotPlayer(int id){
	savings=100;
	//if(id>4 Or id<1){eccezione}
	this->id=id;
}

RobotPlayer::RobotPlayer(const RobotPlayer& r) {
	id = r.id;
	savings = r.savings;
}

bool RobotPlayer::buyout(Square& square){
	srand(time(NULL));
	
	if(rand()%4==0){
		properties.push_back(square);
		//Exchange money;
		return true;
	}
	return false;
}

