#ifndef __THEGAME_H__
#define __THEGAME_H__
#include "card.h"
#include "deck.h"
#include "player.h"
#include "players.h"
#include "hydra.h"
#include "io.h"
#include "turn.h"
#include "move.h"

#include <string>
#include <vector>
#include <memory>

const int no_of_suits = 4;
const int no_of_values = 13;
const int no_of_cards = no_of_suits*no_of_values + 2;

class theGame {
    int no_of_players;
    int cards_per_player;
    Hydra h;
    Players p;
    bool testing;
public:
    theGame(int no_players, int cards, bool test);
    ~theGame();
    void begin();
};

#endif