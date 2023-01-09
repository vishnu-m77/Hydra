#include "players.h"
#include <iostream>

Players::Players() {
    no_of_players = 0;
    currentPlayer = 0;
}

void Players::addPlayer(std::shared_ptr<Player> p1) {
    p.push_back(p1);
    ++no_of_players;
    std::cout << "There are " << no_of_players << " players" << std::endl;
}

std::shared_ptr<Card> Players::nextCard() {
    return p[currentPlayer]->nextCard();
}

void Players::incPlayer() {
    if (currentPlayer == no_of_players - 1) {
        currentPlayer = 0;
        std::cout << currentPlayer << std::endl;
        return;
    }
    ++currentPlayer;
    std::cout << currentPlayer << std::endl;
}
void Players::addToDiscard(std::shared_ptr<Card> c) {
    p[currentPlayer]->addToDiscard(c);
}
void Players::addToDiscard(std::shared_ptr<Deck> d) {
    p[currentPlayer]->addToDiscard(d);
}

int Players::no_of_cards() {
    return p[currentPlayer]->count();
}

int Players::curr_player() {
    return currentPlayer + 1;
}

int Players::no_players() {
    return no_of_players;
}

void Players::print(bool reserve, int no_of_moves_rem) {
    std::cout << "Players: " << std::endl;
    for (int i = 0; i < no_of_players; ++i) {
        int total = p[i]->count();
        int draw = p[i]->sizeDraw();
        int discard = p[i]->sizeDiscard();
        std::cout << "Player " << i+1 << ": " << total << " (";
        std::cout << draw << " draw, " << discard << " discard) ";
        if (i == currentPlayer) {
            std::cout << "+ 1 in hand, " << no_of_moves_rem << " remaining, ";
            std::cout << reserve << " in reserve";
        }
         std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::ostream & operator<<( std::ostream & out, Players & p ) {
    out << "Players: " << std::endl;
    for (int i = 0; i < p.no_of_players; ++i) {
        int total = p.p[i]->count();
        int draw = p.p[i]->sizeDraw();
        int discard = p.p[i]->sizeDiscard();
        out << "Player " << i+1 << ": " << total << " (";
        out << draw << " draw, " << discard << " discard)" << std::endl;
    }
    out << std::endl;
    return out;
}



