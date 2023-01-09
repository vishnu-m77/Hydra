#ifndef __PLAYERS_H__
#define __PLAYERS_H__
#include "card.h"
#include "deck.h"
#include "player.h"
#include <vector>
#include <memory>

class Players {
    friend std::ostream & operator<<( std::ostream & out, Players & p );
    std::vector<std::shared_ptr<Player>> p;
    int no_of_players;
    int currentPlayer;
public:
    Players();
    ~Players(){};
    void addPlayer(std::shared_ptr<Player> p1);
    std::shared_ptr<Card> nextCard();
    void incPlayer();
    void addToDiscard(std::shared_ptr<Card> c);
    void addToDiscard(std::shared_ptr<Deck> d);
    int no_of_cards();
    int curr_player();
    int no_players();
    void print(bool reserve, int no_of_moves_rem);
};

std::ostream & operator<<( std::ostream & out, Players & p );

#endif