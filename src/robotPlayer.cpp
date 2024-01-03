#include "../include/robotPlayer.h"

robotPlayer::robotPlayer(int id){
	savings=100;
	//if(id>4 Or id<1){eccezione}
	this->id=id;
}

bool robotPlayer::buyout(Square& square){
	srand(time(NULL));
	
	if(rand()%4==0){
		properties.push_back(square);
		//Exchange money;
		return true;
	}
	return false;
}


