#include "../include/humanPlayer.h"

HumanPlayer::HumanPlayer(){
	savings=100;
	int id=1;
}

bool HumanPlayer::buyout(Square& square){
	
	properties.push_back(square);
	//exchangeMoney sottrai soldi
	return true;
}


