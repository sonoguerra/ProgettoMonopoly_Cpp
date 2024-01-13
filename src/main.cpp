//Author: Guerra Thomas

#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include "../include/square.h"
#include "../include/board.h"
#include "../include/player.h"
#include "../include/robotPlayer.h"
#include "../include/humanPlayer.h"
#include "../include/game.h"

int main(int argc, char* argv[]) {
    Board board;
    
	/*
	 * Controlli argomento passato da riga di comando
	 */
	if(argc<2) {
		std::cout << "Non hai fornito il parametro da riga di comando" << std::endl;
		return -1;
	}
	
	if(strcmp(argv[1], "computer")!=0 && strcmp(argv[1], "human")!=0) {
		std::cout << "Parametro non valido, inserire: \"computer\" o \"human\"" << std::endl;
		return -1;
	}
	
	/*
	 * Scelta su che tipo di Player istanziare in base al parametro passato
	 */
	std::vector<Player*> players;
	int max_turns;
    
	if(strcmp(argv[1], "computer")==0) {
		players = {new RobotPlayer(1), new RobotPlayer(2), new RobotPlayer(3), new RobotPlayer(4)};
        max_turns = 2;
	}else{
		players = {new HumanPlayer(1), new RobotPlayer(2), new RobotPlayer(3), new RobotPlayer(4)};
        max_turns =  std::numeric_limits<int>::max();
	}
	
	std::cout << "Ordine players iniziale: ";
	for(int i = 0; i < players.size(); i++) {
		std::cout << players.at(i)->get_id() << " ";
	}
	std::cout << std::endl;
	
	Game::players_order(players);
	
	std::cout << "Ordine players finale: ";
	for(int i = 0; i < players.size(); i++) {
		std::cout << players.at(i)->get_id() << " ";
	}
	std::cout << std::endl;
	
	bool is_game_running = true; //determina quando finisce il game
    int count_turns = 0; //contatore dei turni
    int starting_player_id = players.at(0)->get_id(); //serve per determinare quando incrementare count_turns
    int i=0; //indice
    
    std::cout << "---------INIZIO DELLA PARTITA!---------" << std::endl;
    while(is_game_running && count_turns < max_turns) {
        std::cout << "Giocatore " << players.at(i)->get_id();
        int die_value = players.at(i)->dice_throw();
        std::cout << " ha tirato i dadi con esito " << die_value << std::endl;
        
        int square_index = board.move(*players.at(i), die_value);
        Square position = board.square_at(square_index);
        
        //se il giocatore e' arrivato su una square angolare non fa niente
        if(position.get_type() != ' ') {
            //se il giocatore e' arrivato su una square in suo possesso --> possibile upgrade
            if(position.get_owner() != i) {
                //se il giocatore e' arrivato su una square
                if(position.is_unassigned()) {
                    //TODO: buyout
                }
            }else {
                //TODO: upgrade
            }
        } 
        
        //se tutti i player hanno fatto la loro giocata allora e' un nuovo turno
        if(players.at(i)->get_id() == starting_player_id) {
            count_turns++;
        }
        
        i=(++i)%4;
    }
    
	return 0;
}