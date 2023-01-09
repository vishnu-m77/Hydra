#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "card.h"
#include "deck.h"
#include <memory>

class Player {
    std::shared_ptr<Deck> DrawPile;
    std::shared_ptr<Deck> DiscardPile;
public:
    Player(std::shared_ptr<Deck> Draw, std::shared_ptr<Deck> Discard);
    virtual ~Player() {};
    int count();
    bool isEmpty();
    bool DrawPileIsEmpty();
    void RecreateDrawPile();
    std::shared_ptr<Card> nextCard();
    void addToDiscard(std::shared_ptr<Card> c);
    void addToDiscard(std::shared_ptr<Deck> d);
    int sizeDraw();
    int sizeDiscard();
};



#endif