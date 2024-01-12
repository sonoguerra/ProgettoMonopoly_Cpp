//Guerra Thomas
#include "player.h"
#include "robotPlayer.h"
#include "humanPlayer.h"
#include <vector>

class FourPlayers {
public:
	FourPlayers();
	void initialize(Player* p1, Player* p2, Player* p3, Player* p4);
	Player* at(int i);
	const Player* at(int i) const;
	Player* operator[](int i);
	const Player* operator[](int i) const;
private:
	std::vector<Player*> players;
};