#include "hydra.h"
#include <iostream>


Hydra::Hydra() : index{0} {};

void Hydra::addHydraHead(std::shared_ptr<Deck> d) {
    if (d == nullptr) {
        return;
    }
    SetOfDecks.push_back(d);
}

std::shared_ptr<Deck> Hydra::removeHead() {
    std::shared_ptr<Deck> d;
    d = SetOfDecks.front();
    SetOfDecks.erase(SetOfDecks.begin());
    ++index;
    return d;
}

std::shared_ptr<Card> Hydra::backOfDeck(int n) {
    std::shared_ptr<Card> c;
    c = (SetOfDecks[n - index - 1])->back();
    return c;
}

void Hydra::addCardToDeck(std::shared_ptr<Card> c, int n) {
    int size = SetOfDecks.size();
    if (n < index || n > index + size ) {
        return;
    }
    (SetOfDecks[n - index - 1])->push(c);
}

int Hydra::oldestHead() {
    return index;
}

int Hydra::size() {
    return SetOfDecks.size();
}

std::ostream & operator<<( std::ostream & out, Hydra & h ){
    out << "Heads:" << std::endl;
    int index = h.oldestHead() + 1;
    for (int i = 0; i < h.size(); ++i) {
        int printindex = index + i;
        std::string name = h.SetOfDecks[i]->back()->name();
        int size = h.SetOfDecks[i]->size();
        out << printindex << ": " << name << " (" << size << ")" << std::endl;
    }
    out << std::endl;
    return out;
}
