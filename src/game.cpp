//Guerra Thomas
#include "../include/game.h"
#include <iostream>
#include <algorithm>

namespace Game{
	void players_order (std::vector<Player*>& p){
		std::vector<int> dice = {p.at(0)->dice_throw(), p.at(1)->dice_throw(), p.at(2)->dice_throw(), p.at(3)->dice_throw()};
		
		std::cout << "Start: ";
		for(auto i = dice.begin(); i<dice.end(); ++i) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		
		int i = 0;
		int end = dice.size();
		while(i < (end-1)) {
			//sort di p e dice della porzione [i, end[
			for(int j = i; j < end-1; j++) {
				for(int k = j+1; k < end; k++) {
					if(dice.at(j) < dice.at(k)) {
						int d_temp = dice.at(j);
						dice.at(j) = dice.at(k);
						dice.at(k) = d_temp;
								
						Player* p_temp = p.at(j);
						p.at(j) = p.at(k);
						p.at(k) = p_temp; //MEMORY LEAK?
					}
				}
			}
			
			std::cout << "Player: ";
			for(auto i = p.begin(); i<p.end(); ++i) {
				const Player* pointer = *i;
				std::cout << pointer->getId() << " ";
			}
			std::cout << std::endl;
			std::cout << "Middle: ";
			for(auto i = dice.begin(); i<dice.end(); ++i) {
				std::cout << *i << " ";
			}
			std::cout << std::endl;
			
			//se due numeri consecutivi non sono uguali, allora non ci interessa piu' la porzione prima dell' i-esima posizione
			while(i < (end-1) && dice.at(i) != dice.at(i+1)) {
				i++;
			}
			
			//i-esima posizione e' l'elemento pivot con il quale confronto gli elementi successivi attraverso l'indice comp
			//se ci dice.at(comp) e' uguale all'i-esimo, allora ritira il dado
			int comp = i+1; 
			while(comp < end && dice.at(i) == dice.at(comp)) {
				std::cout << "Player " << p.at(comp)->getId() << " ritira dado: ";
				dice.at(comp) = p.at(comp)->dice_throw();
				std::cout << dice.at(comp) << std::endl;
				comp++;
			}
			end = comp; //in caso ci siano degli elementi uguali, sposto end a +1 dall'ultimo elemento uguale all'i-esimo
			
			//se ci sono degli elementi uguali all'i-esimo allora ritira il dado anche i-esimo
			if(comp > (i+1)) {
				std::cout << "Player " << p.at(i)->getId() << " ritira dado: ";
				dice.at(i) = p.at(i)->dice_throw();
				std::cout << dice.at(i) << std::endl;
			}
		}
		
		std::cout << std::endl;
		std::cout << "End: ";
		for(auto i = dice.begin(); i<dice.end(); ++i) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}	
}


	