//Guerra Thomas

#include <iostream>
#include <cstring>
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
	return 0;
}
