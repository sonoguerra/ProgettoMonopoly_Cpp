#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "square.h"

class Player{
protected:
 int savings;
 int id;
 std::vector<Square> properties;
public:
 Player();
 Player(const Player&) = delete;
 Player& operator=(const Player&) = delete;
 int dice_throw() const;
 int add_amount(int amount);
 int remove_amount(int amount);
 virtual bool buyout(Square& square)=0;
 int getSavings(){return savings;};
 int getId() const {return id;};
 void setSavings(int new_amount){savings=new_amount;};
 std::vector<Square>& getBuildings(){return properties;};
 
};
#endif