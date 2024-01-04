#include <time.h>
#include "../include/player.h"

int player::dice_throw(){
	srand(time(NULL));
	
	return (rand()%6)+1;
}

int player::add_amount(int amount){
	if(amount<0){
		//eccezione
	}
	return savings+=amount;
	
}
int player::remove_amount(int amount){
	if(amount<0){
		//eccezione
	}
	return savings-=amount;
}