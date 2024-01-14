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
    const std::vector<Square>& get_board() const;
    const std::vector<int>& get_positions() const;
    Square& square_at(int i);
    int move(Player& player, int dice);
    void buy_property(int i, int player);
    char upgrade_property(int i);
    void delete_property(int i);
    void buy_property(std::string pos, int player);
    char upgrade_property(std::string pos);
    void delete_property(std::string pos);
    Board& operator=(const Board& board);
    Board& operator=(Board&& board);

private:
    std::vector<Square> squares;    //le caselle sono memorizzate come vector di Square. Nonostante le caselle siano individuate da una coppia di coordinate, di fatto il tabellone è costituito solo dal "bordo" della matrice 8x8, quindi utilizzare una matrice costringerebbe ad avere molte celle non utilizzate.
    std::vector<int> positions; //le posizioni dei giocatori all'interno del tabellone sono memorizzate in questo vector.
};

std::string convert_position(int i);
int convert_position(std::string pos);
std::ostream& operator<<(std::ostream& o, const Board& b);
#endif