#ifndef __TURN_H__
#define __TURN_H__
#include "card.h"
#include "deck.h"
#include "player.h"
#include "hydra.h"
#include "move.h"
#include "io.h"

#include <string>
#include <vector>
#include <memory>


class Turn {
   /* int no_of_moves_rem;
    int player_no */
    std::shared_ptr<Card> Hand;
    std::shared_ptr<Card> Reserve;
    bool swapped;
    bool testing;
public:
    Turn(bool testing);
    ~Turn(){};
    int next(Players & p, Hydra & h);
    void swap();
};

void cutHydra(Players & p, Hydra & h, std::shared_ptr<Card> Hand);

#endif