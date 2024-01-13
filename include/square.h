// Author: Davide Pinzan
#ifndef SQUARE_H
#define SQUARE_H
#include <string>

#include <iostream>

class Square
{
public:
    Square();
    Square(std::string position, std::string category);
    std::string get_id() const;
    std::string get_content() const;
    bool is_unassigned() const;
    bool is_house_built() const;
    bool is_hotel_built() const;
    char get_type() const;
    int get_owner() const;
    void add_player(int player);
    void remove_player(int player);
    void buy_property(int player);
    void upgrade();
    void delete_property();

private:
    std::string id;
    std::string content;
    int owner;
};

std::ostream& operator<<(std::ostream& o, const Square& s);

#endif
