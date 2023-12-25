#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>

#include "square.h"

class Board {
    public:
        Board();
        std::vector<Square> get_board() const;
        std::vector<int> get_positions() const;
        Square square_at(int i) const;
        int move(int player, int dice); //da sostituire int con Player
        void upgrade_terrain(int i); //questo metodo e il seguente potrebbero non servire, ma in teoria così evitano il dover ritornare una reference a Square
        void delete_property(int i);
    private:
        std::vector<Square> squares;
        std::vector<int> positions;
};

std::string convert_position(int i);
int convert_position(std::string pos);
std::ostream& operator<<(std::ostream& o, const Board& b);
#endif