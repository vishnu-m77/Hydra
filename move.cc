#include "move.h"

Move::Move(std::shared_ptr<Card> Hand, bool reserve, bool swapped) : Hand{Hand}, reserve{reserve}, swapped{swapped} {};

bool validHead(Hydra & h, int i, bool swapped) {
    bool b = 0;
    if (i >h.oldestHead() && i <= h.oldestHead() + h.size()) {
        // std::cout << "Works at 14" << std::endl;
        b = 1;
    } else if (i == 0) {
        if (h.size() < 2 || swapped) {
            b = 0;
        } else {
            b = 1;
        }
    } else {
        b = 0;
    }
   // std::cout << "Works at 15" << std::endl;
    return b;
}

int Move::next(Hydra &h, int player_no) {
    int r = 0;
    int i = 0;
    while(1) {
        // std::cout << "Works at 11" << std::endl;
        i = getMove(Hand, player_no);
        if (i == -1) {
            break;
        }
        if (!validHead(h, i, swapped)) {
            continue;
        }
        // std::cout << "Works at 12" << std::endl;
        if (i == 0) {
            if (swapped) {
                continue;
            } else {
                r = -2;
                break;
            }
            if (!reserve) {
                r = -2;
                break;
            } 
        }
        break;
    }
    if ( i == -1) {
        return 0-3;
    }
    // std::cout << "Works at 13" << std::endl;
    if (r == -2) {
        return r;
    }
    if (Hand->getSuit()=='J') {
        Hand->setValue(getJoker());
    }
    r = move(h, i, Hand);
    return r;
}

int move(Hydra &hydra, int i, std::shared_ptr<Card> &play) {
    // std::cout << "Works at 16" << std::endl;
    int value = play->getValue();
    // std::cout << "Works at 18" << std::endl;
    std::shared_ptr<Card> c = hydra.backOfDeck(i);
    // std::cout << "Works at 19" << std::endl;
    int Hydravalue = c->getValue();
    // std::cout << "Works at 20" << std::endl;
    // std::cout << Hydravalue << std::endl;
    if (Hydravalue == 1) {
        hydra.addCardToDeck(c, i);
        return 1;
    }
    if (value <= Hydravalue) {
        hydra.addCardToDeck(c, i);
        if (value == Hydravalue) {
            return 0;
        }
        return 1;
    }
    if ( i != hydra.oldestHead() && possibleMoves(hydra, value)) {
        return -1;
    } else {
        // cut the Hydra head
        return 2;
    }
}

bool possibleMoves(Hydra &hydra, int value) {
    // std::cout << "Works at 17" << std::endl;
    bool b = 0;
    int pos = hydra.oldestHead() + 1;
    for (int i = 0; i < hydra.size(); ++i) {
       //  std::cout << "Works at 21" << std::endl;
        int Hydravalue = (hydra.backOfDeck(pos))->getValue();
       // std::cout << "Works at 22" << std::endl;
        if (value <= Hydravalue) {
            b = 1;
            break;
        }
        ++pos;
    }
   //  std::cout << "Works at 23" << std::endl;
    return b;
}

