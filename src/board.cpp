#include "../include/board.h"
#include <stdexcept>
#include <cstdlib>

Board::Board() {

}

/*std::vector<std::string> Board::get_squares() {

    return squares;

}*/

std::string convert_position(int i) {
    std::string position;
    if (i < 0 || i > 27) throw std::invalid_argument("Invalid argument: specified position must be between 0 and 27 (included).");
    if (i < 8) {
        position = "A" + std::to_string(i+1);
    } else if (i < 20) {
        position = (char) (i/2 + 62); //migliorare casting?
        position += std::to_string(i%2*7 + 1);
    } else {
        position = "H" + std::to_string(i-19);
    }
    return position;
}

//TODO: leggermente più complesso dell'altra versione
int convert_position(std::string pos) {
    int position = 0;
    return position;
}