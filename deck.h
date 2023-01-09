#ifndef __DECK_H__
#define __DECK_H__
#include "card.h"
#include <vector>
#include <memory>

class Deck {
    std::vector<std::shared_ptr<Card>>SetOfCards;
public:
    Deck();
    virtual ~Deck(){};
    bool isEmpty();
    std::shared_ptr<Card> back();
    void pop();
    void push(std::shared_ptr<Card> c);
    void shuffle();
    int size();
};



#endif