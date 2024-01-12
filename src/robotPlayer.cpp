#include "../include/robotPlayer.h"
#include "../include/exchangeMoney.h"



RobotPlayer::RobotPlayer(){	
	srand(time(NULL));	
	savings=100;
	id=0;
}


RobotPlayer::RobotPlayer(int id){
	srand(time(NULL));	
	savings=100;
	//if(id>4 Or id<1){eccezione}
	this->id=id;
}



RobotPlayer::RobotPlayer(const RobotPlayer& rb){
	this->savings=rb.savings;
	this->id=rb.id;
	this->properties=rb.properties;
}

RobotPlayer& RobotPlayer::operator=(const RobotPlayer& rb){
	this->savings=rb.savings;
	this->id=rb.id;
	this->properties=rb.properties;
	return *this;
}


bool RobotPlayer::buyout(Square& square){
		
	if(rand()%4==0){
		
		log.open("prova.txt", std::ios::app);
		remove_amount(exchangeMoney::buying_price(square));
		properties.push_back(square);
		std::string printLog="Giocatore "+std::to_string(id)+" ha acquistato il terreno "+"\n";	
		log<<printLog;	
		log.close();
		return true;
	}
	return false;
}

bool RobotPlayer::build_house(Square& square){
	
	if(rand()%4==0){
	log.open("prova.txt", std::ios::app);	
	remove_amount(exchangeMoney::building_cost(square));
	square.upgrade();
	std::string printLog="Giocatore "+std::to_string(id)+" ha costruito una casa sul terreno "+"\n";
	log<<printLog;
	log.close();
	return true;
	}
	return false;
}


bool RobotPlayer::build_hotel(Square& square){
		
	if(rand()%4==0){
	log.open("prova.txt", std::ios::app);	
	remove_amount(exchangeMoney::building_cost(square));
	square.upgrade();
	std::string printLog="Giocatore "+std::to_string(id)+" ha migliorato una casa in albergo sul terreno "+"\n";
	log<<printLog;
	log.close();
	return true;
	}
	return false;
}

