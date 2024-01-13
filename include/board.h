// Author: Davide Pinzan
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "square.h"
#include "player.h"

class Board
{
public:
    Board();
    Board(const Board& board);
    Board(Board&& board);
    std::vector<Square> get_board() const;
    std::vector<int> get_positions() const;
    Square& square_at(int i);
    int move(Player& player, int dice);
    void buy_property(int i, int player);
    void upgrade_property(int i);
    void delete_property(int i);
    void buy_property(std::string pos, int player);
    void upgrade_property(std::string pos);
    void delete_property(std::string pos);
    Board& operator=(const Board& board);
    Board& operator=(Board&& board);

private:
    std::vector<Square> squares;
    std::vector<int> positions;
};

std::string convert_position(int i);
int convert_position(std::string pos);
std::ostream& operator<<(std::ostream& o, const Board& b);
#endif