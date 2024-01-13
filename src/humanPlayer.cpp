#include "../include/humanPlayer.h"

HumanPlayer::HumanPlayer(){		
}

HumanPlayer::HumanPlayer(int id){
	savings=100;
	this->id=id;
}

HumanPlayer::HumanPlayer(const HumanPlayer& hp){
	this->savings=hp.savings;
	this->id=hp.id;
	this->properties=hp.properties;
}

HumanPlayer& HumanPlayer::operator=(const HumanPlayer& hp){
	this->savings=hp.savings;
	this->id=hp.id;
	this->properties=hp.properties;
	return *this;
}


bool HumanPlayer::buyout(Square& square){	
	log.open("prova.txt", std::ios::app);	
	remove_amount(buying_price(square));
	properties.push_back(square);
	std::string printLog="Giocatore "+std::to_string(id)+" ha acquistato il terreno "+square.get_id()+"\n";	
	log<<printLog;	
	log.close();
	return true;
}

bool HumanPlayer::build_house(Square& square){	
	log.open("prova.txt", std::ios::app);

	remove_amount(building_cost(square));
	square.upgrade();
	std::string printLog="Giocatore "+std::to_string(id)+" ha costruito una casa sul terreno "+square.get_id()+"\n";	
	std::cout<<square.get_id();
	log<<printLog;
	log.close();
	return true;
}

bool HumanPlayer::build_hotel(Square& square){	
	log.open("prova.txt", std::ios::app);
	remove_amount(building_cost(square));
	square.upgrade();
	std::string printLog="Giocatore "+std::to_string(id)+" ha migliorato una casa in albergo sul terreno "+square.get_id()+"\n";	
	log<<printLog;
	log.close();
	return true;
}



