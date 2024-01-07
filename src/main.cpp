#include <iostream>
#include <string>
#include "../include/board.h"

int main() {
    Board b;
    std::cout << b << std::endl;

    std::cout << "TUTTE LE CASELLE" << std::endl;
    std::vector<Square> array = b.get_board();
    for (int i = 0; i < 28; i++) {
        std::cout << array.at(i) << "\t";
    }
    return 0;
}