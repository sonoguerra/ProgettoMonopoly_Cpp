//Author: Coletto Damiano
#include <time.h>
#include "../include/player.h"

//Costruttore di Default di Player che inizializza srand al fine di poter creare un lancio di dadi pseudo-casuale.
Player::Player(){
	srand(time(NULL));
	savings=100;
	id=0;	
}
/*Metodo che ritorna un numero intero compreso tra 2 e 12 simulando il lancio simultaneo di 2 dadi,
  scrive sul log quale giocatore ha fatto suddetto lancio e il risultato. */
int Player::dice_throw(){
    log.open("log.txt", std::ios::app);
	int dice=(rand()%11) + 2;
	log<<"Giocatore "<<id<<" ha tirato i dadi ottenendo un valore di "<< dice<<std::endl;
    log.close();
	return dice;
}
/*Metodo che aggiunge una quantita' di denaro dal fondo del giocatore e ritorna il nuovo saldo, 
  lancia eccezione nel caso amount sia negativo. */
int Player::add_amount(int amount){
	if(amount<0){
		throw std::invalid_argument("Invalid argument: specified amount must be a positive integer.");
	}
	return savings+=amount;	
}
/*Metodo che sottrae una quantita' di denaro dal fondo del giocatore e ritorna il nuovo saldo,
  lancia eccezione nel caso amount sia negativo. */
int Player::remove_amount(int amount){
	if(amount<0){
		throw std::invalid_argument("Invalid argument: specified amount must be a positive integer.");
	}
	return savings-=amount; 
}
/*Metodo che viene invocato una volta che il player ha perso, le sue proprieta' vengono resettate e rese nuovamente disponibili 
  grazie al metodo di square. Viene scritto sul log quale giocatore ha perso. */  
void Player::reset_properties(){
    log.open("log.txt", std::ios::app);
    for(int i=0;i<properties.size();i++) {
        properties.at(i)->delete_property();
    }
    std::string printLog="Giocatore "+std::to_string(id)+" ha perso"+"\n";
    log<<printLog;			
    log.close();
}
//Metodo che scrive su log quale giocatore ha vinto!
void Player::winner_log(){
	log.open("log.txt", std::ios::app);
	log << "Giocatore " + std::to_string(players.at(i)->get_id()) + " ha vinto\n";
	log.close();
}

/*Metodo che rimuove una quantita' di denaro dal fondo dal giocatore finito in proprieta' altrui, determinata dalla square passata,
  per poi aggiungerla al proprietario.
  Nel caso il debitore dovesse finire i soldi gli vengono sottratti i rimanenti e aggiunti al creditore.
  Il metodo ritorna un booleano per segnalare se la transazione e' avvenuta per completo o il debitore ha finito i soldi.
  Nel log viene riportata la transazione effettuata. */
bool pay_someone(Player& owner,Player& borrower,const Square& square){
	log.open("log.txt", std::ios::app);	
	int amount=passing_cost(square);	
	if(borrower.get_savings()-amount<0){
		owner.add_amount(borrower.get_savings());		
		std::string printLog="Giocatore "+std::to_string(borrower.get_id())+" ha pagato "+std::to_string(borrower.get_savings())+" a Giocatore "+std::to_string(owner.get_id())+" per pernottamento nella casella "+square.get_id()+"\n";
		log<<printLog;			
		log.close();
		return false;
	}
    owner.add_amount(amount);
	borrower.remove_amount(amount);
	std::string printLog="Giocatore "+std::to_string(borrower.get_id())+" ha pagato "+std::to_string(amount)+" a Giocatore "+std::to_string(owner.get_id())+" per pernottamento nella casella"+square.get_id()+"\n";
	log<<printLog;	
	log.close();
	return true;
}
//Metodo che aggiunge 20 fiorini al saldo del player una volta passato dal via, la transazione viene riportata nel log.
void passing_prize(Player& p1){
	log.open("log.txt", std::ios::app);
	p1.add_amount(20);
	std::string printLog="Giocatore "+std::to_string(p1.get_id())+" è passato dal via e ha ritirato 20 fiorini"+"\n";
	log<<printLog;
	log.close();
}	
//Metodo che ritorna un intero contenente il costo di acquisto di una determinata square passato come parametro.
int buying_price(const Square& square){
	char type=square.get_type();	
	switch(type) {
	 case 'E':
		return 6;
	  break;
     case 'S':
	    return 10;
	  break;      
	 case 'L':
	    return 20;  
	  break;
     default:
		return 0;
	}

	
}
/*Metodo che ritorna un intero contenente il costo di costruzione di una casa o del miglioramento di essa in albergo
  in base al parametro square passato. */
int building_cost(const Square& square){
	char type=square.get_type();	
	switch(type) {
	 case 'E':
		return 3;
	  break;
     case 'S':
	    return 5;
	  break;      
	 case 'L':
	    return 10;  
	  break;
     default:
		return 0;
	} 
}	
	
/*Metodo ritornante un intero che, in base al parametro square passato, 
  ritorna l'ammontare che un player deve pagare per il pernottamento. */
int passing_cost(const Square& square){
    char type=square.get_type();
    switch(type){
     case 'E':
        if(square.is_house_built()==true){
                return 2;
        }else if(square.is_hotel_built()==true){
                return 4;
        }
      break;
     case 'S':
      if(square.is_house_built()==true){
                return 4;
        }else if(square.is_hotel_built()==true){
                return 8;
        }
      break;
     case 'L':
      if(square.is_house_built()==true){
                return 7;
        }else if(square.is_hotel_built()==true){
                return 14;
        }
      break;
     default:
        return 0;
    } 
    return 0;
 }
