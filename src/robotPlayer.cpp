//Author: Coletto Damiano
#include "../include/robotPlayer.h"


/*Costruttore di Default RobotPlayer */
RobotPlayer::RobotPlayer(){	
	srand(time(NULL));
	savings=100;
	id=0;
}
/*Costruttore di RobotPlayer che imposta id uguale al parametro passato, lancia eccezione se id non e' valido */
RobotPlayer::RobotPlayer(int id){
	srand(time(NULL));
	savings=100;
	if(id>4 || id<1){throw std::invalid_argument("Id del Player non compreso tra 1 e 4");}
	this->id=id;
}
//Costruttore di copia RobotPlayer
RobotPlayer::RobotPlayer(const RobotPlayer& rb){
	this->savings=rb.savings;
	this->id=rb.id;
	this->properties=rb.properties;
}
//Assegnamento di copia RobotPlayer
RobotPlayer& RobotPlayer::operator=(const RobotPlayer& rb){
	this->savings=rb.savings;
	this->id=rb.id;
	this->properties=rb.properties;
	return *this;
}

/*Metodo che passato una square decide al 25% se comprarla,
 In caso positivo rimuove il relativo costo di acquisione dal saldo del player e
 aggiunge tale square al vettore di proprieta' (properties).
 Scrive attraverso il log quale Giocare ha comprato quale terreno. 
 */
bool RobotPlayer::buyout(Square& square){		
	if(rand()%4==0){		
		log.open("log.txt", std::ios::app);
		remove_amount(buying_price(square));
        square.buy_property(id);
		properties.push_back(&square);
		std::string printLog="Giocatore "+std::to_string(id)+" ha acquistato il terreno "+"\n";	
		log<<printLog;	
		log.close();
		return true;
	}
	return false;
}

/*Metodo che passato una square decide al 25% se edificaci casa.
 *In caso positivo rimuove il relativo costo di costruzione di una casa dal saldo del player,
 richiama il metodo upgrade di square che aggiunge alla casella il relativo simbolino e scrive sul log quale giocatore ha costruito casa
 su quale terreno. */
bool RobotPlayer::build_house(Square& square){	
	if(rand()%4==0){
	log.open("log.txt", std::ios::app);	
	remove_amount(building_cost(square));
	square.upgrade();
	std::string printLog="Giocatore "+std::to_string(id)+" ha costruito una casa sul terreno "+"\n";
	log<<printLog;
	log.close();
	return true;
	}
	return false;
}

/*Metodo che passato una square decide al 25% se migliorare la casa in un albergo.
  In caso positivo rimuove il relativo costo di miglioramento in albergo dal saldo del player,
  richiama il metodo upgrade di square che aggiunge alla casella il relativo simbolino e scrive 
  sul log quale giocatore ha migliorato in albergo e su quale terreno. */
bool RobotPlayer::build_hotel(Square& square){		
	if(rand()%4==0){
	log.open("log.txt", std::ios::app);	
	remove_amount(building_cost(square));
	square.upgrade();
	std::string printLog="Giocatore "+std::to_string(id)+" ha migliorato una casa in albergo sul terreno "+"\n";
	log<<printLog;
	log.close();
	return true;
	}
	return false;
}

