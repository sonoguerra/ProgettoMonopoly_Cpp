#ifndef PLAYERS_ORDER
#define PLAYERS_ORDER
#include <vector>
#include "player.h"

class PlayersOrder  {
	int dice_results[4];
public:
	PlayersOrder(const int* d) {
		for(int i=0; i<4; i++) {
			dice_results[i] = d[i];
		}
	}
	
	bool operator() (const Player& p1, const Player& p2) const {
		return dice_results[p1.getId()-1] < dice_results[p2.getId()-1];
	}
};
#endif