//Author: Coletto Damiano
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <fstream>
#include "square.h"

/*Classe base con la quale si sviluppa l'idea di "Giocatore" per poterla implementare correttamente nelle classi figlie.
  Avendo funzioni virtuali pure non e' possibile crearne un istanza (classe astratta).
  Possiede un array di proprieta' di caselle, un saldo per comprare e pagare altri player, un relativo id per l'identificazione
  ed un log con il quale sara' possibile scrivere i risultati delle varie azioni fatte. */
class Player{
protected:
 int savings; 
 int id;
 std::vector<Square*> properties;
 std::ofstream log;
 
public:
 Player();
 Player(const Player&) = delete; //necessario da disabilitare in una classe astratta
 Player& operator=(const Player&) = delete; ///necessario da disabilitare in una classe astratta
 int dice_throw();
 int add_amount(int amount);
 int remove_amount(int amount);
 virtual bool build_house(Square& square)=0; //metodo virtuale puro
 virtual bool build_hotel(Square& square)=0; //metodo virtuale puro
 virtual bool buyout(Square& square)=0; 	 //metodo virtuale puro
 int get_savings() const{return savings;};
 int get_id() const{return id;};
 void set_savings(int new_amount){savings=new_amount;};
 const std::vector<Square*>& get_buildings() const{return properties;};
 void reset_properties();
 void winner_log();
};

//helper function per Player, utili per scambio di informazioni con altri player o per interagire con le square della Board
int passing_cost(const Square& square);
int building_cost(const Square& square);
int buying_price(const Square& square);
bool pay_someone(Player& p1,Player& p2,const Square& square);
void passing_prize(Player& p1);
#endif
