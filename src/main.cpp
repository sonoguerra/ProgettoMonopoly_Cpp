//Guerra Thomas

#include <iostream>
#include <vector>
#include <cstring>
#include "../include/player.h"
#include "../include/robotPlayer.h"
#include "../include/humanPlayer.h"

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
	 if(strcmp(argv[1], "computer")==0) {
		RobotPlayer r1(1);
		RobotPlayer r2(2);
		RobotPlayer r3(3);
		RobotPlayer r4(4);
		
		
	 }
	return 0;
}

void whoseTurnIs(const Player& p1, const Player& p2, const Player& p3, const Player& p4) {
	std::vector<int> diceResults = {p1.dice_throw()};
}
