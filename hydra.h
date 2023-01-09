#ifndef __HYDRA_H__
#define __HYDRA_H__
#include "deck.h"
#include "card.h"
#include <vector>

class Hydra {
    friend std::ostream & operator<<( std::ostream & out, Hydra & h );
    int index;
    std::vector<std::shared_ptr<Deck>>SetOfDecks;
public:
    Hydra();
    virtual ~Hydra(){};
    void addHydraHead(std::shared_ptr<Deck> d);
    std::shared_ptr<Deck> removeHead();
    std::shared_ptr<Card> backOfDeck(int n);
    void addCardToDeck(std::shared_ptr<Card> c, int n);
    // returns the index of the oldest HydraHead
    int oldestHead();
    int size();
};

std::ostream & operator<<( std::ostream & out, Hydra & h );

#endif