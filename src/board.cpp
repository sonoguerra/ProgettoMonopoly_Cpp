// Author: Davide Pinzan
#include "../include/board.h"
#include <stdexcept>
#include <cstdlib>

Board::Board()
{
    srand(time(NULL));
    positions = {0, 0, 0, 0};   //vengono aggiunti tutti i giocatori nella casella di partenza in posizione 0
    squares.push_back(Square(convert_position(0), "P"));
    squares.at(0).add_player(1);
    squares.at(0).add_player(2);
    squares.at(0).add_player(3);
    squares.at(0).add_player(4);
    int count_economy = 0, count_standard = 0, count_luxury = 0;
    for (int i = 1; i < 28; i++)
    {
        if ((i % 7) == 0)
        {
            squares.push_back(Square(convert_position(i), " "));    //genera le caselle angolari nelle posizioni multiple di 7
        }
        else
        {
            bool valid = false;
            do
            {
                int select = rand() % 3;    //le altre caselle vengono generate 
                switch (select)
                {
                case 0:
                    if (count_economy < 8)
                    {
                        squares.push_back(Square(convert_position(i), "E"));
                        count_economy++;
                        valid = true;
                    } 
                    break;
                case 1:
                    if (count_standard < 10)
                    {
                        squares.push_back(Square(convert_position(i), "S"));
                        count_standard++;
                        valid = true;
                    }


                    break;
                case 2:
                    if (count_luxury < 6)
                    {
                        squares.push_back(Square(convert_position(i), "L"));
                        count_luxury++;
                        valid = true;
                    }
                    break;
                }
            } while (!valid);
        }
    }
}

Board::Board(const Board& board) {
    squares = board.get_board();
    positions = board.get_positions();
}

Board::Board(Board&& board) {
    squares = board.get_board();
    positions = board.get_positions();
}

std::vector<Square> Board::get_board() const
{
    return squares;
}

std::vector<int> Board::get_positions() const
{
    return positions;
}

Square& Board::square_at(int i)
{
    return squares.at(i%28);
}

int Board::move(Player& player, int dice)
{
    int player_id = player.get_id();
    int start = positions[player_id];
    squares.at(start).remove_player(player_id);
    int end = (start + dice) % 28;
    squares.at(end).add_player(player_id);
    positions[player_id] = end;
    if (start > 15 && end < 12) passing_prize(player);
    return end; // ritorna la posizione della casella dove finisce il giocatore.
}

void Board::buy_property(int i, int player)
{
    squares.at(i).buy_property(player);
}

void Board::upgrade_property(int i)
{
    squares.at(i).upgrade();
}

void Board::delete_property(int i)
{
    squares.at(i).delete_property();
}

void Board::buy_property(std::string pos, int player)
{
    buy_property(convert_position(pos), player);
}

void Board::upgrade_property(std::string pos)
{
    upgrade_property(convert_position(pos));
}

void Board::delete_property(std::string pos)
{
    delete_property(convert_position(pos));
}

Board& Board::operator=(const Board& board) {
    squares = board.get_board();
    positions = board.get_positions();
    return *this;
}

Board& Board::operator=(Board&& board) {
    squares = board.get_board();
    positions = board.get_positions();
    return *this;
}

std::string convert_position(int pos)
{
    std::string position;
    if (pos < 0)
        throw std::invalid_argument("Invalid argument: specified position must be a positive integer.");


    int i = pos % 28;
    if (i < 8)
    {
        position = "H" + std::to_string(8 - i);
    }
    else if (i < 15)
    {
        position = (char)(79 - i);
        position += "1";
    }
    else if (i < 22)
    {
        position = "A" + std::to_string(i - 13);
    }
    else
    {
        position = (char)(i + 44);
        position += "8";
    }
    return position;
}

int convert_position(std::string pos)
{
    int position = 0;
    if (pos.length() != 2)
        throw std::invalid_argument("Invalid argument: position must be exactly 2 characters long.");
    char letter_part = pos.at(0);
    int numerical_part = std::stoi(pos.substr(1, 1));
    if (letter_part < 'A' || letter_part > 'H')
        throw std::invalid_argument("Invalid argument: position row must be between A and H (included).");
    if (numerical_part < 1 || numerical_part > 8 || ((letter_part != 'A' && letter_part != 'H') && (numerical_part != 1 && numerical_part != 8)))
        throw std::invalid_argument("Invalid argument: specified column is not a valid number.");
    if (letter_part == 'H')
    {
        position = 8 - numerical_part;
    }
    else if (letter_part == 'A')
    {
        position = numerical_part + 13;
    }
    else if (numerical_part == 8)
    {
        position = (int)(letter_part - 44);
    }
    else
    {
        position = (int)(79 - letter_part);
    }
    return position;
}

std::ostream& operator<<(std::ostream &o, const Board &b)
{
    std::vector<Square> board = b.get_board();
    std::string output = "";
    int i;
    for (i = 0; i < 8; i++)
    {
        output = board.at(i).get_content() + "\t" + output;
    }
    output = "\n" + output;
    for (i = 8; i < 14; i++)
    {
        output = board.at(i).get_content() + "\t\t\t\t\t\t\t" + board.at(35 - i).get_content() + output;
        output = "\n" + output;
    }
    for (i = 21; i > 13; i--)
    {
        output = board.at(i).get_content() + "\t" + output;
    }
    return o << output;
}