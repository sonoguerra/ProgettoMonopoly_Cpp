// Author: Davide Pinzan
// Author: Davide Pinzan
#include "../include/square.h"
#include <stdexcept>

Square::Square()
{
Square::Square()
{
    content = "| |";
    owner = 0;
    owner = 0;
}

Square::Square(std::string position, std::string category)
{
    if (position.length() != 2)
        throw std::invalid_argument("Invalid argument: position must be exactly 2 characters long.");
    char letter_part = position.at(0);
    int numerical_part = std::stoi(position.substr(1, 1));
    if (letter_part < 'A' || letter_part > 'H')
        throw std::invalid_argument("Invalid argument: position row must be between A and H (included).");
    if (numerical_part < 1 || numerical_part > 8 || ((letter_part != 'A' || letter_part != 'H') && (numerical_part != 1 || numerical_part != 8)))
        throw std::invalid_argument("Invalid argument: specified column is not a valid number.");
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
std::string Square::get_id() const
{
    return id;
}

std::string Square::get_content() const
{
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
void Square::buy_property(int player)
{
    owner = player;
}

void Square::delete_property()
{
    if (is_hotel_built() || is_house_built())
        content.erase(2, 1);
    owner = 0;
void Square::delete_property()
{
    if (is_hotel_built() || is_house_built())
        content.erase(2, 1);
    owner = 0;
}

std::ostream& operator<<(std::ostream& o, const Square& s)
{
std::ostream& operator<<(std::ostream& o, const Square& s)
{
    return o << s.get_content();
}