//Author: Guerra Thomas

#include "../include/game.h"
#include <iostream>

namespace Game{
    //funzione per stabilire l'ordine dei giocatori in base ai dadi tirati
    void players_order(std::vector<Player*>& p){
        //vector di dadi
        std::vector<int> dice = {p.at(0)->dice_throw(), p.at(1)->dice_throw(), p.at(2)->dice_throw(), p.at(3)->dice_throw()};

        std::cout << "Tiro dadi iniziale: ";
        for(auto i = dice.begin(); i<dice.end(); ++i) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
        
        int i = 0; //indice di inizio vector
        int end = dice.size(); //indice di fine vector
        
        //ciclo che effettua sort di dice e p 
        //ogni ciclo vengono fissati i valori non uguali all'inizio o fine del vector
        //mentre se i giocatori hanno tirato uguale --> ritirano dado
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
                        p.at(k) = p_temp;
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
    
    void show(const std::vector<Player*>& p, const Board& b) {
        std::cout << b << std::endl;
        std::cout << std::endl;
        
        //vector delle square possedute dai giocatori
        std::vector<std::vector<Square*>> square_print;
        for(int i = 0; i < p.size(); i++) {
            square_print.push_back(p.at(i)->get_buildings());
        }
        
        //stampa le square possedute dai giocari
        std::cout << "PROPRIETA':" << std::endl;
        for(int i = 0; i < square_print.size(); i++) {
            std::cout << "Giocatore " << p.at(i)->get_id() << ": ";
            for(int j = 0; j < square_print.at(i).size(); j++) {
                std::cout <<  square_print.at(i).at(j)->get_id() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        
        //vector che contiene i savings dei giocatori
        std::vector<int> savings_print;
        for(int i = 0; i < p.size(); i++) {
            savings_print.push_back(p.at(i)->get_savings());
        }
        
        //stampa i savings dei giocatori
        std::cout << "FIORINI:" << std::endl;
        for(int i = 0; i < savings_print.size(); i++) {
            std::cout << "Giocatore " << p.at(i)->get_id() << ": " << savings_print.at(i) << std::endl;
        }
        std::cout << std::endl;
    }
    
    //function che trova la square associata al giocatore
    int find_square_owner(const std::vector<Player*>& p, const Square& s) {
        for(int i=0; i < p.size(); i++) {
            if(p.at(i)->get_id() == s.get_owner())
                return i;
        }
        
        return -1; 
    }
    
    //rimuove il giocatore nel vector di indice index, liberando la memoria
    void delete_player(std::vector<Player*>& p, int index) {
        while(index != (p.size()-1)) {
            int i = index+1;
            Player* p_temp = p.at(index);
            p.at(index) = p.at(i);
            p.at(i) = p_temp;
            index++;
        }
        
        p.at(p.size()-1)->reset_properties(); 
        delete p.at(p.size()-1);
        p.at(p.size()-1) = nullptr;
        p.pop_back();
    }
}