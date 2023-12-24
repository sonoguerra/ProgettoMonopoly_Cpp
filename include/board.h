#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>

#include "square.h"

class Board {
    public:
        Board();
        std::vector<Square> get_squares();
    private:
        std::vector<Square> squares;
        std::vector<int> positions;
};

std::string convert_position(int i);
int convert_position(std::string pos);
#endif