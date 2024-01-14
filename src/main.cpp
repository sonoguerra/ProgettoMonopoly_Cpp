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
    std::ofstream file;
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
	int max_turns = 50;
    
	if(strcmp(argv[1], "computer") == 0) {
		players = {new RobotPlayer(1), new RobotPlayer(2), new RobotPlayer(3), new RobotPlayer(4)};
	}else{
		players = {new HumanPlayer(1), new RobotPlayer(2), new RobotPlayer(3), new RobotPlayer(4)};
        std::cout << std::endl;
        std::cout << "Sei il Giocatore 1!" << std::endl;
        std::cout << std::endl;
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
    
    std::cout << std::endl;
    std::cout << "---------INIZIO DELLA PARTITA!---------" << std::endl;
    
    if(strcmp(argv[1], "human") == 0)
        std::cout << "LEGENDA: S->si, N->no, show->mostra tabellone, le proprieta' e l'ammontare di fiorini" << std::endl;
    else
        std::cout << "PARTITA IN CORSO..." << std::endl;
        
    std::cout << std::endl;
    
    int i=0; //indice
    while(is_game_running && count_turns < max_turns) {
        int dice_value = players.at(i)->dice_throw();
        bool has_lost = false; //indica se bisogna scrivere la fine del turno di un giocatore eliminato
        
        //stampa solo se partita con umano
        if(strcmp(argv[1], "human") == 0) {
            if(i == 0) {
                std::cout << "----------------TURNO " << std::to_string(count_turns) << "----------------" << std::endl;
            }
            std::cout << "Giocatore " << players.at(i)->get_id();
            std::cout << " ha tirato i dadi con esito " << dice_value << std::endl;
        }
        
        //se tutti i player hanno fatto la loro giocata allora e' un nuovo turno
        if(players.at(i)->get_id() == players.at(players.size()-1)->get_id()) {
            count_turns++;
        }
        
        //stampa solo se partita con umano
        int square_index = board.move(*players.at(i), dice_value);
        Square& position = board.square_at(square_index);
        if(strcmp(argv[1], "human") == 0) {
            std::cout << "Giocatore " << players.at(i)->get_id();
            std::cout << " e' arrivato sulla cella " << position.get_id() << std::endl;
        }
        
        //se il giocatore e' arrivato su una square angolare non fa niente
        if(position.get_type() != ' ' && position.get_type() != 'P') {
            //se il giocatore non e' arrivato su una square in suo possesso
            if(position.get_owner() != players.at(i)->get_id()) {
                //se il giocatore e' arrivato su una square libera --> possibile buyout
                if(position.is_unassigned()) {
                    //se il giocatore ha abbastanza soldi per comprare la square --> possibile buyout
                    if(players.at(i)->get_savings() >= buying_price(position)) {
                        //se giocatore e' umano --> input
                        if(players.at(i)->get_id() == 1 && strcmp(argv[1], "human") == 0) {
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
                        }
                        //se giocatore non e' umano --> possibile buyout
                        else {
                            bool has_bought = players.at(i)->buyout(position); //controlla se buyout e' andato a buon fin (25%)
                            //stampa solo se partita con umano
                            if(has_bought && strcmp(argv[1], "human") == 0) {
                                std::cout << "Giocatore " << players.at(i)->get_id() << " ha comprato il terreno " << position.get_id() << std::endl;
                            }
                        }
                    //se il giocatore non ha abbastanza soldi per comprare il square --> non permette l'acquisto
                    }else {
                        //stampa solo se partita con umano
                        if(strcmp(argv[1], "human") == 0) {
                            std::cout << "Giocatore " << players.at(i)->get_id() << " non ha abbastanza fiorini per comprare il terreno" 
                            << std::endl;
                        }
                    }
                }
                //se il giocatore e' arrivato su una square di un altro giocatore --> possibile pagamento del pernottamento
                else {
                    int j = Game::find_square_owner(players, position);
                    
                    //stampa solo se partita con umano
                    if(strcmp(argv[1], "human") == 0) {
                        std::cout << "Giocatore " << players.at(i)->get_id() << " e' arrivato in un terreno di Giocatore" 
                        << players.at(j)->get_id() << std::endl;
                    }
                    
                    //se il giocatore e' arrivato su una square di un altro giocatore con casa o albergo --> paga pernottamento
                    //altrimenti non fa niente
                    if(position.is_house_built() || position.is_hotel_built()) {
                        bool has_paid = pay_someone(*players.at(j), *players.at(i), position); //controlla ha abbastanza soldi per pagare il pernottamento
                        
                        if(strcmp(argv[1], "human") == 0) {
                            std::cout << "Giocatore " << players.at(i)->get_id() << " ha pagato " << passing_cost(position) 
                            << " fiorini a Giocatore " << players.at(j)->get_id() << std::endl;
                        }
                        
                        //se giocatore non ha pagato --> ha perso
                        if(!has_paid) {
                            //stampa solo se partita con umano
                            if(strcmp(argv[1], "human") == 0) {
                                    std::cout << "Giocatore " << players.at(i)->get_id() << " ha perso" << std::endl;
                            }
                            has_lost = true;
                            Game::delete_player(players, i);
                        }
                    }//se non e' stata costruita una casa o un albergo --> non fa niente
                }
            }
            //se il giocatore e' arrivato su una square in suo possesso --> possibile upgrade
            else {
                //controlla se giocatore ha abbastanza soldi per costruire
                //altrimenti non fa upgrade
                if(players.at(i)->get_savings() >= building_cost(position)) {
                    //se la casa e' stata costruita --> possibile upgrade con hotel
                    if(position.is_house_built()) {
                        //se l'hotel non e' stato costruito --> possibile upgrade con hotel
                        //altrimenti non fa niente
                        if(!position.is_hotel_built()) {
                            //se giocatore e' umano --> input
                            if(players.at(i)->get_id() == 1 && strcmp(argv[1], "human") == 0) {
                                std::string input;
                                do{
                                    input = "";
                                    std::cout << "Vuoi costruire un hotel? (S/N/show) ";
                                    std::cin >> input;
                                    if(input == "show" || input == "SHOW") {
                                        Game::show(players, board);
                                    }
                                }while(input != "s" && input != "S" && input != "n" && input != "N");
                                        
                                if(input == "s" || input == "S") {
                                    players.at(i)->build_hotel(position);
                                    std::cout << "Giocatore " << players.at(i)->get_id() << " ha costruito un hotel in " 
                                    << position.get_id() << std::endl;
                                }
                            }
                            //se giocatore non e' umano --> possibile upgrade con hotel
                            else {
                                bool has_built = players.at(i)->build_hotel(position); //controlla se giocatore computer ha costruito (25%)
                                //stampa solo se giocatore umano
                                if(has_built && strcmp(argv[1], "human") == 0) {
                                    std::cout << "Giocatore " << players.at(i)->get_id() << " ha costruito un hotel in " 
                                    << position.get_id() << std::endl;
                                }
                            }
                        }
                    }
                    //se casa non e' stata costruita --> possibile upgrade con casa
                    else {
                        //stampa solo se partita con umano
                        if(players.at(i)->get_id() == 1 && strcmp(argv[1], "human") == 0) {
                            std::string input;
                            do{
                                input = "";
                                std::cout << "Vuoi costruire una casa? (S/N/show) ";
                                std::cin >> input;
                                if(input == "show" || input == "SHOW") {
                                    Game::show(players, board);
                                }
                            }while(input != "s" && input != "S" && input != "n" && input != "N");
                                    
                            if(input == "s" || input == "S") {
                                players.at(i)->build_house(position);
                                std::cout << "Giocatore " << players.at(i)->get_id() << " ha costruito una casa in " 
                                << position.get_id() << std::endl;
                            }
                        }
                        //se giocatore non e' umano --> possibile upgrade con casa
                        else {
                            bool has_built = players.at(i)->build_house(position); //controlla se giocatore computer ha costruito (25%)
                            
                            //stampa solo se partita con umano
                            if(has_built && strcmp(argv[1], "human") == 0) {
                                std::cout << "Giocatore " << players.at(i)->get_id() << " ha costruito una casa in " 
                                << position.get_id() << std::endl;
                            }
                        }
                    }
                }
                //se il giocatore non ha abbastanza soldi per costruire sulla square --> non permette upgrade
                else {
                    //stampa solo se partita con umano
                    if(strcmp(argv[1], "human") == 0) {
                        std::cout << "Giocatore " << players.at(i)->get_id() << " non ha abbastanza fiorini per costruire sul terreno" 
                        << std::endl;
                    }
                }
            }
        }//giocatore arrivato in una cella angolare --> non fa niente
        
        //stampa solo se partita con umano
        if(strcmp(argv[1], "human") == 0)
            std::cout << std::endl;
            
        //se rimane un solo giocatore --> ha vinto
        if(players.size() == 1) {
            is_game_running = false;
            std::cout << "Giocatore " << players.at(0)->get_id() << " ha vinto";
        }
        
        if(!has_lost) {
            file.open("prova.txt", std::ios::app);
            file << "Giocatore " + std::to_string(players.at(i)->get_id()) + " ha finito il turno\n";
            file.close();
        }
        
        i = (i+1) % players.size();
    }
    
    std::cout << std::endl;
    std::cout << "--------- FINE DELLA PARTITA!---------" << std::endl;
    std::cout << std::endl;
    
    Game::show(players, board);
    
    if(is_game_running) {
        int max_fiorini = 0;
        
        for(int i = 0; i < players.size(); i++) {
            if(players.at(i)->get_savings() > max_fiorini) {
                max_fiorini = players.at(i)->get_savings();
            }
        }
        
        for(int i = 0; i < players.size(); i++) {
            if(players.at(i)->get_savings() == max_fiorini) {
                std::cout << "Giocatore " << players.at(i)->get_id() << " ha vinto!" << std::endl;
                file.open("prova.txt", std::ios::app);
                file << "Giocatore " + std::to_string(players.at(i)->get_id()) + " ha vinto\n";
                file.close();
            }
        }
    }
	return 0;
}