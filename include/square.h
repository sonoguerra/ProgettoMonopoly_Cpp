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
    char upgrade();
    void delete_property();

private:
    std::string id; //id è la posizione in coordinate lettera|numero della casella, utilizzato come identificatore univoco della stessa.
    std::string content;    //il contenuto della casella sono tutte le informazioni utili ad essere visualizzate (presenza di giocatori, edifici, tipo...).
    int owner;  //owner rappresenta il giocatore proprietario della casella.
};

std::ostream& operator<<(std::ostream& o, const Square& s);

#endif
