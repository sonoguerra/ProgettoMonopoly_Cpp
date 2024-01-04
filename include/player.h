#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "square.h"

class player{
protected:
 int savings;
 int id;
 std::vector<Square> properties;
public:
 player(){};
 player(const player&) = delete;
 player& operator=(const player&) = delete;
 int dice_throw();
 int add_amount(int amount);
 int remove_amount(int amount);
 virtual bool buyout(Square& square)=0;
 int getSavings(){return savings;};
 int getId(){return id;};
 void setSavings(int new_amount){savings=new_amount;};
 std::vector<Square>& getBuildings(){return properties;};
 
};
#endif