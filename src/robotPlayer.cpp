#include "../include/robotPlayer.h"

RobotPlayer::RobotPlayer(int id){
	savings=100;
	//if(id>4 Or id<1){eccezione}
	this->id=id;
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


