#include <iostream>
#include <string>
#include "../include/board.h"

int main() {
    Board b;
    b.move(1, 8);
    b.move(1, 8);
    std::cout << b << std::endl;
    b.upgrade_terrain(10);
    std::cout << b << std::endl;
    b.delete_property(10);
    std::cout << b;
    return 0;
}