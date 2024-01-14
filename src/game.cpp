//Guerra Thomas
#include "../include/game.h"
#include <iostream>

namespace Game{
    void players_order(std::vector<Player*>& p){
        std::vector<int> dice = {p.at(0)->dice_throw(), p.at(1)->dice_throw(), p.at(2)->dice_throw(), p.at(3)->dice_throw()};

        std::cout << "Tiro dadi iniziale: ";
        for(auto i = dice.begin(); i<dice.end(); ++i) {
            std::cout << *i << " ";
        }
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
            //se due numeri consecutivi non sono uguali, allora non ci interessa piu' la porzione prima dell' i-esima posizione
            while(i < (end-1) && dice.at(i) != dice.at(i+1)) {
                i++;
            }
            
            //i-esima posizione e' l'elemento pivot con il quale confronto gli elementi successivi attraverso l'indice comp
            //se ci dice.at(comp) e' uguale all'i-esimo, allora ritira il dado
            int comp = i+1; 
            while(comp < end && dice.at(i) == dice.at(comp)) {
                std::cout << "Player " << p.at(comp)->get_id() << " ritira dadi: ";
                dice.at(comp) = p.at(comp)->dice_throw();
                std::cout << dice.at(comp) << std::endl;
                comp++;
            }
            end = comp; //in caso ci siano degli elementi uguali, sposto end a +1 dall'ultimo elemento uguale all'i-esimo
            
            //se ci sono degli elementi uguali all'i-esimo allora ritira il dado anche i-esimo
            if(comp > (i+1)) {
                std::cout << "Player " << p.at(i)->get_id() << " ritira dadi: ";
                dice.at(i) = p.at(i)->dice_throw();
                std::cout << dice.at(i) << std::endl;
            }
        }
        
        std::cout << "Ordine dadi finale: ";
        for(auto i = dice.begin(); i<dice.end(); ++i) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
    }
    /*
    void human_buyout(Player& p, const Board& b, const Square& s) {
        std::string input;
        do{
            input = "";
            std::cout << "Vuoi comprare il terreno di tipo " << s.get_type() << "? (S/N/show/prop) ";
            std::cin >> input;
            if(input == "show" || input == "SHOW") {
                show(p, b);
            }else if(input == "prop" || input == "PROP") {
                
            }
        }while(input != "s" && input != "S" && input != "n" && input != "N");
        
        if(input == "s" || input == "S") {
            p.buyout(s);
        }
        
    }*/
    
    void show(const std::vector<Player*>& p, const Board& b) {
        std::cout << b << std::endl;
        std::cout << std::endl;
        
        std::vector<std::vector<Square>> square_print = {p.at(0)->get_buildings(), p.at(1)->get_buildings(), 
        p.at(2)->get_buildings(), p.at(3)->get_buildings()};
        
        std::cout << "PROPRIETA':" << std::endl;
        for(int i = 0; i < square_print.size(); i++) {
            std::cout << "Giocatore " << p.at(i)->get_id() << ": ";
            for(int j = 0; j < square_print.at(i).size(); j++) {
                std::cout <<  square_print.at(i).at(j).get_id() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        
        std::cout << "FIORINI:" << std::endl;
        std::vector<int> savings_print = {p.at(0)->get_savings(), p.at(1)->get_savings(), p.at(2)->get_savings(), p.at(3)->get_savings()};
        for(int i = 0; i < savings_print.size(); i++) {
            std::cout << "Giocatore " << p.at(i)->get_id() << ": " << savings_print.at(i) << std::endl;
        }
        std::cout << std::endl;
    }
    
    int find_square_owner(const std::vector<Player*>& p, const Square& s) {
        for(int i=0; i < p.size(); i++) {
            if(p.at(i)->get_id() == s.get_owner())
                return i;
        }
        
        return -1;
    }
}