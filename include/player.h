#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <fstream>
#include "square.h"

class Player{
protected:
 int savings; 
 int id;
 std::vector<Square> properties;
 std::ofstream log;
 
public:
 Player();
 Player(const Player&) = delete;
 Player& operator=(const Player&) = delete;
 int dice_throw();
 int add_amount(int amount);
 int remove_amount(int amount);
 virtual bool build_house(Square& square)=0; 
 virtual bool build_hotel(Square& square)=0; 
 virtual bool buyout(Square& square)=0;
 int get_savings(){return savings;};
 int get_id(){return id;};
 void set_savings(int new_amount){savings=new_amount;};
 std::vector<Square>& get_buildings(){return properties;};
 


};
int passing_cost(const Square& square);
int building_cost(const Square& square);
int buying_price(const Square& square);
bool pay_someone(Player& p1,Player& p2,const Square& square);
void passing_prize(Player& p1);
#endif