//Guerra Thomas
#ifndef GAME_H
#define GAME_H
#include <vector>
#include <algorithm>
#include "../include/player.h"
#include "../include/robotPlayer.h"
#include "../include/humanPlayer.h"

namespace Game {
	void players_order(std::vector<Player*>& p);
}
#endif