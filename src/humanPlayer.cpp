//Author: Coletto Damiano
#include "../include/humanPlayer.h"
//Costruttore di default di humanPlayer che imposta arbitrariamente savings=100
HumanPlayer::HumanPlayer(){
        savings=100;
		id=0;
}
/*Costruttore di HumanPlayer che imposta id uguale al parametro passato, lancia eccezione se id non e' valido. */
HumanPlayer::HumanPlayer(int id){
	savings=100;
	this->id=id;
	if(id>4 || id<1) throw std::invalid_argument("Invalid argument: specified id must be between 1 and 4.");
}
//Costruttore di copia HumanPlayer
HumanPlayer::HumanPlayer(const HumanPlayer& hp){
	this->savings=hp.savings;
	this->id=hp.id;
	this->properties=hp.properties;
}
//Assegnamento di copia di HumanPlayer
HumanPlayer& HumanPlayer::operator=(const HumanPlayer& hp){
	this->savings=hp.savings;
	this->id=hp.id;
	this->properties=hp.properties;
	return *this;
}
/*Metodo che passato uno square rimuove il relativo costo di acquisione dal saldo del player e
 aggiunge tale square al vettore di proprieta' (properties).
 Scrive attraverso il log quale Giocare ha comprato quale terreno. 
 */
bool HumanPlayer::buyout(Square& square){	
	log.open("log.txt", std::ios::app);
	remove_amount(buying_price(square));
	square.buy_property(id);
	properties.push_back(&square);
	std::string printLog="Giocatore "+std::to_string(id)+" ha acquistato il terreno "+square.get_id()+"\n";	
	log<<printLog;	
	log.close();
	return true;
}

/*Metodo che passato uno square rimuove il relativo costo di costruzione di una casa dal saldo del player,
 richiama il metodo upgrade di square che aggiunge alla casella il relativo simbolo e scrive sul log quale giocatore ha costruito 
 su quale terreno.*/
bool HumanPlayer::build_house(Square& square){	
	log.open("log.txt", std::ios::app);	
	remove_amount(building_cost(square));
	square.upgrade();
	std::string printLog="Giocatore "+std::to_string(id)+" ha costruito una casa sul terreno "+square.get_id()+"\n";
	log<<printLog;
	log.close();
	return true;
}

/*Metodo che passato una square rimuove il relativo costo di miglioramento di una casa in albergo dal saldo del player,
 richiama il metodo upgrade di square che aggiunge alla casella il relativo simbolino e scrive sul log quale giocatore ha migliorato
 casa in albergo su quale terreno. */
bool HumanPlayer::build_hotel(Square& square){	
	log.open("log.txt", std::ios::app);
	remove_amount(building_cost(square));
	square.upgrade();
	std::string printLog="Giocatore "+std::to_string(id)+" ha migliorato una casa in albergo sul terreno "+square.get_id()+"\n";	
	log<<printLog;
	log.close();
	return true;
}



