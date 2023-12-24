#include <iostream>
#include <string>
#include "../include/square.h"

int main() {
    Square s("E");
    s.add_player(1);
    std::cout << s;
    s.remove_player(1);
    std::cout << s;
    return 0;
}