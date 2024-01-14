//Guerra Thomas

#include <iostream>
#include <vector>
#include <cstring>
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
	if(argc <2 ) {
		std::cout << "Non hai fornito il parametro da riga di comando" << std::endl;
		return -1;
	}
	
	if(strcmp(argv[1], "computer") !=0 && strcmp(argv[1], "human") != 0) {
		std::cout << "Parametro non valido, inserire: \"computer\" o \"human\"" << std::endl;
		return -1;
	}
	
	/*
	 * Scelta su che tipo di Player istanziare in base al parametro passato
	 */
    std::vector<Player*> players;
	int max_turns = 100;
    
	if(strcmp(argv[1], "computer") == 0) {
		players = {new RobotPlayer(1), new RobotPlayer(2), new RobotPlayer(3), new RobotPlayer(4)};
	}else{
		players = {new HumanPlayer(1), new RobotPlayer(2), new RobotPlayer(3), new RobotPlayer(4)};
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
    int count_turns = 1; //contatore dei turni
    int last_player_id = players.at(3)->get_id(); //serve per determinare quando incrementare count_turns
    int i=0; //indice
    
    std::cout << std::endl;
    std::cout << "---------INIZIO DELLA PARTITA!---------" << std::endl;
    std::cout << "LEGENDA: S->si, N->no, show->mostra tabellone, le proprieta' e l'ammontare di fiorini" << std::endl;
    std::cout << std::endl;
    
    while(is_game_running && count_turns < max_turns) {
        //se tutti i player hanno fatto la loro giocata allora e' un nuovo turno
        if(players.at(i)->get_id() == last_player_id) {
            count_turns++;
            std::cout << "----------------TURNO " << count_turns << "----------------" << std::endl;
        }
        
        std::cout << "Giocatore " << players.at(i)->get_id();
        int dice_value = players.at(i)->dice_throw();
        std::cout << " ha tirato i dadi con esito " << dice_value << std::endl;
        
        int square_index = board.move(*players.at(i), dice_value);
        Square& position = board.square_at(square_index); //tenere copia?
        std::cout << "Giocatore " << players.at(i)->get_id();
        std::cout << " e' arrivato sulla cella " << position.get_id() << std::endl;
        
        //se il giocatore e' arrivato su una square angolare non fa niente
        if(position.get_type() != ' ' && position.get_type() != 'P') {
            //se il giocatore non e' arrivato su una square in suo possesso
            if(position.get_owner() != players.at(i)->get_id()) {
                //se il giocatore e' arrivato su una square libera --> possibile buyout
                if(position.is_unassigned()) {
                    //se il giocatore ha abbastanza soldi per comprare la square --> possibile buyout
                    if(players.at(i)->get_savings() >= buying_price(position)) {
                        //TODO: buyout
                        if(players.at(i)->get_id() == 1) {
                            std::string input;
                            do{
                                input = "";
                                std::cout << "Vuoi comprare il terreno di tipo " << position.get_type() << "? (S/N/show) ";
                                std::cin >> input;
                                if(input == "show" || input == "SHOW") {
                                    Game::show(players, board);
                                }
                            }while(input != "s" && input != "S" && input != "n" && input != "N");
                            
                            if(input == "s" || input == "S") {
                                players.at(i)->buyout(position);
                                std::cout << "Giocatore " << players.at(i)->get_id() << " ha comprato il terreno " << position.get_id() << std::endl;
                            }
                        }else {
                            if(players.at(i)->buyout(position)) {
                                std::cout << "Giocatore " << players.at(i)->get_id() << " ha comprato il terreno " << position.get_id() << std::endl;
                            }
                        }
                    //se il giocatore non ha abbastanza soldi per comprare il square --> non permette l'acquisto
                    }else {
                        std::cout << "Giocatore " << players.at(i)->get_id() << " non ha abbastanza fiorini per comprare il terreno" 
                        << std::endl;
                    }
                //se il giocatore e' arrivato su una square di un altro giocatore --> possibile pagamento del pernottamento
                }else {
                    int j = Game::find_square_owner(players, position);
                    std::cout << "Giocatore " << players.at(i)->get_id() << " e' arrivato in un terreno di Giocatore" 
                        << players.at(j)->get_id() << std::endl;
                        
                    //se il giocatore e' arrivato su una square di un altro giocatore con casa o albergo --> paga pernottamento
                    //altrimenti non fa niente
                    if(position.is_house_built() || position.is_hotel_built()) {
                        //se giocatore ha abbastanza soldi per pagare --> paga pernottamento
                        if(pay_someone(*players.at(j), *players.at(i), position)) {
                            std::cout << "Giocatore " << players.at(i)->get_id() << " ha pagato " << passing_cost(position) 
                            << " fiorini a Giocatore " << players.at(j)->get_id() << std::endl;
                        }
                        //giocatore ha perso
                        else {
                            std::cout << "Giocatore " << players.at(i)->get_id() << " ha perso" << std::endl;
                            players.at(i)->reset_properties();
                        }
                    }
                }
            //se il giocatore e' arrivato su una square in suo possesso --> possibile upgrade
            }else {
                if(players.at(i)->get_savings() >= building_cost(position)) {
                    //TODO: upgrade
                    std::cout << "upgrade" << std::endl;
                }
                //se il giocatore non ha abbastanza soldi per costruire sulla square --> non permette upgrade
                else {
                    std::cout << "Giocatore " << players.at(i)->get_id() << " non ha abbastanza fiorini per costruire sul terreno" 
                    << std::endl;
                }
            }
        }else {
            /*
             * NON NECESSARIO
            if(players.at(i)->get_id() == 1) {
                std::string input;

                do{
                    input = "";
                    std::cout << "Vuoi visualizzare il tabellone? (show/N) ";
                    std::cin >> input;
                }while(input != "show" && input != "SHOW" && input != "n" && input != "N");
                
                if(input == "show" || input == "SHOW") {
                    Game::show(*players.at(i), board);
                }
            }*/
        }
        
        std::cout << std::endl;
        i = (++i)%4;
    }
    
	return 0;
}