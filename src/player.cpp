#include <time.h>
#include "../include/player.h"

Player::Player(){
	srand(time(NULL));
	savings=100;
	id=0;	
}

int Player::dice_throw(){	
	int dice=(rand()%6)+1;
	log<<"Giocatore "<<id<<" ha tirato i dadi ottenendo un valore di "<< dice<<std::endl;
	return dice;
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