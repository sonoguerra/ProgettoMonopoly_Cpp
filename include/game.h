//Author: Guerra Thomas

#ifndef GAME_H
#define GAME_H
#include <vector>
#include "../include/player.h"
#include "../include/board.h"
#include "../include/square.h"

namespace Game {
	void players_order(std::vector<Player*>& p);
    void show(const std::vector<Player*>& p, const Board& b);
    int find_square_owner(const std::vector<Player*>& p, const Square& s);
    void delete_player(std::vector<Player*>& p, int index);
}
#endif