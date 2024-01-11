// Author: Davide Pinzan
#include "../include/square.h"
#include <stdexcept>

Square::Square()
{
    content = "| |";
    owner = 0;
}

//Validità
Square::Square(std::string position, std::string category)
{
    if (category != " " && category != "E" && category != "S" && category != "L" && category != "P")
        throw std::invalid_argument("Invalid argument: only valid arguments are characters P, S, L, E and blank space.");
    content = "|" + category + "|";
    id = position;
    owner = 0;
}

std::string Square::get_id() const
{
    return id;
}

std::string Square::get_content() const
{
    return content;
}

bool Square::is_unassigned() const
{
    if (owner == 0)
        return true;
    return false;
}

bool Square::is_house_built() const
{
    return (content.at(2) == '*');
}

bool Square::is_hotel_built() const
{

    
    return (content.at(2) == '^');
}

char Square::get_type() const
{
    return content.at(1);
}

int Square::get_owner() const
{
    return owner;
}

void Square::add_player(int player)
{
    content.insert(content.length() - 1, std::to_string(player));
}

void Square::remove_player(int player)
{
    int pos = content.find(std::to_string(player));
    content.erase(pos, 1);
}

void Square::upgrade()
{
    if (is_house_built())
        content.at(2) = '^';
    else if (!is_hotel_built())
        content.insert(2, "*");
}

void Square::buy_property(int player)
{
    owner = player;
}

void Square::delete_property()
{
    if (is_hotel_built() || is_house_built())
        content.erase(2, 1);
    owner = 0;
}

std::ostream& operator<<(std::ostream& o, const Square& s)
{
    return o << s.get_content();
}