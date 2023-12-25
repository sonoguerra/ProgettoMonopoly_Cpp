#include "../include/board.h"
#include <stdexcept>
#include <cstdlib>

Board::Board() {
    srand(time(NULL));                                          //se questa viene chiamata nel main prima di tutto il resto forse qui non serve
    positions = {0, 0, 0, 0};
    squares.push_back(Square("P"));
    squares.at(0).add_player(1);
    squares.at(0).add_player(2);
    squares.at(0).add_player(3);
    squares.at(0).add_player(4);
    int count_economy = 0, count_standard = 0, count_luxury = 0;
    for (int i = 1; i < 28; i++) {
        if (i == 7 || i == 20 || i == 27) {
            squares.push_back(Square());
        } else {
            bool valid = false;
            do {
                int select = rand()%3;
                switch (select) {
                    case 0:
                        if (count_economy < 8) {
                            squares.push_back(Square("E"));
                            count_economy++;
                            valid = true;
                        }                                       //migliorabile forse generando prima tutte le caselle e poi riordinandole in maniera casuale. Trovare un modo per non indentare così tanto.
                        break;
                    case 1:
                        if (count_standard < 10) {
                            squares.push_back(Square("S"));
                            count_standard++;
                            valid = true;
                        }
                        break;
                    case 2:
                        if (count_luxury < 6) {
                            squares.push_back(Square("L"));
                            count_luxury++;
                            valid = true;









                        }
                        break;         
            }
            } while (!valid);
        }
    }
}

std::vector<Square> Board::get_board() const {
    return squares;
}

std::vector<int> Board::get_positions() const {
    return positions;
}

Square Board::square_at(int i) const {
    return squares.at(i);                                   //implementare circolare?
}

int Board::move(int player, int dice) {                     //questa funzione non fa controlli sui numeri validi perché poi li dovrà fare Player
    int start = positions[player];
    squares.at(start).remove_player(player);
    int end = (start + dice) % 28;
    squares.at(end).add_player(player);
    positions[player] = end;
    //if (start > 15 && end >= 0) Player.give(20);
    return end;                                             //ritorna la posizione della casella dove finisce il giocatore, quindi dopo questa se si vuole vedere lo stato della casella bisogna chiamare square_at(end)
}

void Board::upgrade_terrain(int i) {
    squares.at(i).upgrade();
}

void Board::delete_property(int i) {
    squares.at(i).delete_property();
}

//corretto per come viene visualizzato il tabellone adesso ma non per come dovrebbe essere fatto
std::string convert_position(int pos) {
    std::string position;
    if (pos < 0) throw std::invalid_argument("Invalid argument: specified position must be a positive integer.");
    int i = pos % 28;
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

//da rifare in modo che stampi le caselle partendo da in basso a destra e nell'ordine corretto
std::ostream& operator<<(std::ostream& o, const Board& b) {
    int i;
    for (i = 0; i < 8; i++) {
        o << b.square_at(i) << "\t";
    }
    o << std::endl;
    for (i; i < 20; i=i+2) {
        o << b.square_at(i) << "\t\t\t\t\t\t\t" << b.square_at(i+1) << std::endl;
    }
    for (i; i < 28; i++) {
        o << b.square_at(i) << "\t";
    }
    return o;
}