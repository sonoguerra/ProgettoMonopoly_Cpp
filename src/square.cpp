// Author: Davide Pinzan
#include "../include/square.h"
#include <stdexcept>

Square::Square()
{
    content = "| |";    //Il costruttore di default inizializza la casella a una casella angolare.
    owner = 0;  //Assegnare 0 a "owner" significa che la casella non ha ancora un proprietario.
}

Square::Square(std::string position, std::string category)
{
    if (position.length() != 2)
        throw std::invalid_argument("Invalid argument: position must be exactly 2 characters long.");
    char letter_part = position.at(0);
    int numerical_part = std::stoi(position.substr(1, 1));
    if (letter_part < 'A' || letter_part > 'H')
        throw std::invalid_argument("Invalid argument: position row must be between A and H (included).");
    if (numerical_part < 1 || numerical_part > 8 || ((letter_part != 'A' && letter_part != 'H') && (numerical_part != 1 && numerical_part != 8)))
        throw std::invalid_argument("Invalid argument: specified column is not a valid number.");   //controllo di validità per capire se la posizione inserita sia valida o meno.
    if (category != " " && category != "E" && category != "S" && category != "L" && category != "P")
        throw std::invalid_argument("Invalid argument: only valid arguments are characters P, S, L, E and blank space.");   //controllo di validità per capire se la tipologia della casella sia valida.
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
    return (owner == 0);
}

bool Square::is_house_built() const
{


    return (content.at(2) == '*');  //il carattere in posizione 2 è l'identificativo dell'edificio costruito sulla casella
}

bool Square::is_hotel_built() const
{
    return (content.at(2) == '^');
}

char Square::get_type() const
{
    return content.at(1);   //il carattere in posizione 1 è la tipologia di terreno (economica, lusso, standard, partenza o angolare)
}

int Square::get_owner() const
{
    return owner;
}

void Square::add_player(int player)
{
    content.insert(content.length() - 1, std::to_string(player));   //aggiunge il giocatore alla casella nella posizione prima del carattere finale |
}

void Square::remove_player(int player)
{
    int pos = content.find(std::to_string(player));
    content.erase(pos, 1);
}

char Square::upgrade()
{
    if (is_house_built()) 
    {   
        content.at(2) = '^';    //sostituisce il carattere che rappresenta la casa con quello per l'albergo se l'upgrade viene richiesto su una casella con casa
        return '^';
    }
    else if (!is_hotel_built()) //controlla che non ci sia costruito un hotel, nel qual caso l'upgrade non sortisce alcun effetto
    {
        content.insert(2, "*"); //aggiunge nella seconda posizione il carattere rappresentativo della casa
        return '*';
    }
    return ' '; //ritorna spazio se non viene eseguita la modifica
}

void Square::buy_property(int player)
{
    owner = player;
}

void Square::delete_property()
{
    if (is_hotel_built() || is_house_built())
        content.erase(2, 1);    //cancella le proprietà costruite e resetta il proprietario
    owner = 0;
}

std::ostream& operator<<(std::ostream& o, const Square& s)
{
    return o << s.get_content();
}