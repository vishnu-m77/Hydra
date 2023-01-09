#ifndef __MOVE_H__
#define __MOVE_H__
#include "card.h"
#include "deck.h"
#include "player.h"
#include "hydra.h"
#include "io.h"

#include <string>
#include <vector>
#include <memory>

class Move{
    std::shared_ptr<Card> Hand;
    bool reserve;
    bool swapped;
public:
    Move(std::shared_ptr<Card> Hand, bool reserve, bool swapped);
    ~Move() {};
    int next(Hydra &h, int player_no);
};

bool validHead(Hydra & h, int i, bool swapped);

bool possibleMoves(Hydra &hydra, int value);

int move(Hydra &hydra, int i, std::shared_ptr<Card> &play);

#endif