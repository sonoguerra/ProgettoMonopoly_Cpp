#include "../include/humanPlayer.h"

humanPlayer::humanPlayer(){
	savings=100;
	int id=1;
}

bool humanPlayer::buyout(Square& square){
	
	properties.push_back(square);
	//exchangeMoney sottrai soldi
	return true;
}


