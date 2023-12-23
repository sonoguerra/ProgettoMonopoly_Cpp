#include "../include/board.h"
#include <cmath>

/*std::vector<std::string> Board::get_squares() {

    return squares;

}*/

//aggiungere eccezioni
std::string convert_position(int i) {
    std::string position;
    if (i < 8) {
        position = "A" + std::to_string(i+1);
    } else if (i < 20) {
        position = (char) (i/2 + 62);
        position += std::to_string(i%2*7 + 1);
    } else {
        position = "H" + std::to_string(i-19);
    }
    return position;
}