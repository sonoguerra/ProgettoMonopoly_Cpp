#include "../include/humanPlayer.h"

HumanPlayer::HumanPlayer(){
	savings=100;
	int id=1;
}

HumanPlayer::HumanPlayer(int id){
	savings=100;
	//if(id>4 Or id<1){eccezione}
	this->id=id;
}
bool HumanPlayer::buyout(Square& square){
	
	properties.push_back(square);
	//exchangeMoney sottrai soldi
	return true;
}


