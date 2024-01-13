//Guerra Thomas

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include "../include/player.h"
#include "../include/robotPlayer.h"
#include "../include/humanPlayer.h"
#include "../include/game.h"

int main(int argc, char* argv[]) {
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
	
	if(strcmp(argv[1], "computer")==0) {
		players = {new RobotPlayer(1), new RobotPlayer(2), new RobotPlayer(3), new RobotPlayer(4)};
	}else{
		players = {new HumanPlayer(1), new RobotPlayer(2), new RobotPlayer(3), new RobotPlayer(4)};
	}
	
	std::cout << "Ordine players iniziale: ";
	for(auto i = players.begin(); i<players.end(); ++i) {
		const Player* pointer = *i;
		std::cout << pointer->getId() << " ";
	}
	std::cout << std::endl;
	
	Game::players_order(players);
	
	std::cout << "Ordine players finale: ";
	for(auto i = players.begin(); i<players.end(); ++i) {
		const Player* pointer = *i;
		std::cout << pointer->getId() << " ";
	}
	std::cout << std::endl;
	
	
	return 0;
}
