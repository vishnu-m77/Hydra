#include "deck.h"
#include "card.h"
#include "hydra.h"
#include "player.h"
#include "players.h"
#include "io.h"
#include "turn.h"
#include "move.h"
#include "theGame.h"

#include <string>
#include <iostream>
#include <memory>

int main(int argc, char* argv[]) {
    int no_of_players = 2;
    int cards_per_player = 54;
    while (1) {
        std::cout << "Enter number of players: " << std::endl;
        std::string s;
        getline(std::cin, s );
        if (std::cin.fail()) {
            s = "";
            break;
        }
        try {
         no_of_players = std::stoi(s);
        } catch (...) {
            continue;
        }
        break;
    }
    while (1) {
        std::cout << "Enter number of cards per player: " << std::endl;
        std::string s;
        getline(std::cin, s );
        if (std::cin.fail()) {
            s = "";
            break;
        }
        try {
         cards_per_player = std::stoi(s);
        } catch (...) {
            continue;
        }
        break;
    }
    bool testing = 0;
    if (argc != 1) {
        std::string s = argv[1];
        if (s[0] == '-') {
            if (s == "-testing") {
                testing = 1;
            }
        }
    } 
    theGame(no_of_players, cards_per_player, testing);

    return 0;
}


