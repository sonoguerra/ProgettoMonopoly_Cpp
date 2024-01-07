#include <time.h>
#include "../include/player.h"

int Player::dice_throw() const{
	srand(time(NULL));
	
	return (rand()%6)+1;
}

int Player::add_amount(int amount){
	if(amount<0){
		//eccezione
	}
	return savings+=amount;
	
}
int Player::remove_amount(int amount){
	if(amount<0){
		//eccezione
	}
	return savings-=amount;
}