#include <time.h>
#include "../include/player.h"

Player::Player(){
	srand(time(NULL));
	savings=100;
	id=0;	
}

int Player::dice_throw(){
    log.open("prova.txt", std::ios::app);
	int dice=(rand()%11) + 2;
	log<<"Giocatore "<<id<<" ha tirato i dadi ottenendo un valore di "<< dice<<std::endl;
    log.close();
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

void Player::reset_properties(){
    std::ofstream scrittura("prova.txt", std::ios::app);
    for(int i=0;i<properties.size();i++) {
        properties.at(i)->delete_property();
    }
    std::string printLog="Giocatore "+std::to_string(id)+" ha perso"+"\n";
    scrittura<<printLog;			
    scrittura.close();
}

bool pay_someone(Player& owner,Player& borrower,const Square& square){
	std::ofstream scrittura("prova.txt", std::ios::app);	
	int amount=passing_cost(square);	
	if(borrower.get_savings()-amount<0){
		owner.add_amount(borrower.get_savings());
		//borrower.set_savings(0);
		std::string printLog="Giocatore "+std::to_string(borrower.get_id())+" ha pagato "+std::to_string(borrower.get_savings())+" a Giocatore "+std::to_string(owner.get_id())+" per pernottamento nella casella "+square.get_id()+"\n";
		scrittura<<printLog;			
		scrittura.close();
		return false;
	}
    owner.add_amount(amount);
	borrower.remove_amount(amount);	
	//std::cout<<	"Giocatore "+std::to_string(borrower.get_id())+" ha pagato "+std::to_string(amount)+" a Giocatore "+std::to_string(owner.get_id())+" per pernottamento nella casella"+"\n";

	std::string printLog="Giocatore "+std::to_string(borrower.get_id())+" ha pagato "+std::to_string(amount)+" a Giocatore "+std::to_string(owner.get_id())+" per pernottamento nella casella"+square.get_id()+"\n";
	scrittura<<printLog;	
	scrittura.close();
	return true;
}
	
void passing_prize(Player& p1){
	std::ofstream scrittura("prova.txt", std::ios::app);
	p1.add_amount(20);
	std::string printLog="Giocatore "+std::to_string(p1.get_id())+" è passato dal via e ha ritirato 20 fiorini"+"\n";
	scrittura<<printLog;	
	scrittura.close();
}	

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