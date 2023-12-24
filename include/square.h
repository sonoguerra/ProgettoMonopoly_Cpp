#ifndef SQUARE_H
#define SQUARE_H
#include <string>

#include <iostream>


class Square {
    public:
        Square();
        Square(std::string category); //da vedere se usare un enum di char, ma è una feature di C++11. Vedere se si può quantomeno convertire a char.
        std::string get_content() const;
        bool is_house_built() const;
        bool is_hotel_built() const;
        void add_player(int player);
        void remove_player(int player);
        void upgrade();
        void delete_property();
    private:
        std::string content;
};

std::ostream& operator<<(std::ostream& o, const Square& s);

#endif