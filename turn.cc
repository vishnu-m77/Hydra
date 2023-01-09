#include "turn.h"

Turn::Turn(bool testing) :  swapped{false}, testing{testing} {};

int Turn::next(Players &p, Hydra &h) {
    // special print here please
    printHead(h);
    // printPlayer(p);
    int win = 0;
    int no_of_moves_rem = h.size();
    int player_no = p.curr_player();
    printTurn(player_no);
    // b = -1 means the input was invalid and the 
    // move is repeated with the same card in hand.
    // b = -2 means the card in Hand has been placed 
    // into the Reserve and the move is repeated with a new card.
    // b = -3 means EOF and the function quits.
    // b = 1 means the move was a success
    // b = 0 means the turn has ended abruptly
    // b = 2 means the head of the hydra has been cut
    for(int i = 0; i < h.size(); ++i) {
        int b = -1;
        if (!swapped) {
            Hand = p.nextCard();
        }
        if (testing) {
            Hand = getCard();
        }
        no_of_moves_rem -= 1;
        while(1) {
            bool d = 0;
            if (Reserve != nullptr) {
                d = 1;
            }
            printMove(h, p, d, no_of_moves_rem);
            Move m(Hand, d, swapped);
            b = m.next(h, player_no);
            if (b != -1) {
                break;
            }
        }
        if (b == -3) {
            win = -1;
            break;
        }
        if (b == -2) {
            --i;
            ++no_of_moves_rem;
            swap();
            continue;
        }
        if (p.no_of_cards() == 0) {
            if (Reserve == nullptr) {
                win = 1;
                break;
            } else {
                if (no_of_moves_rem != 0) {
                    b = 0;
                }
            }
        }
       if (b == 2) {
            cutHydra(p, h, Hand);
            break;
        } 
        if (b == 0) {
            break;
        }
    }
    if (Reserve != nullptr) {
        p.addToDiscard(Reserve);
    }
    return win;
}

void Turn::swap() {
    if (Reserve == nullptr) {
        Reserve = std::move(Hand);
        return;
    }
    Hand.swap(Reserve);
    swapped = 1;
}

void cutHydra(Players &p, Hydra &h, std::shared_ptr<Card> Hand) {
    std::shared_ptr<Deck> d = h.removeHead();
    d->push(Hand);
    p.addToDiscard(d);
    std::shared_ptr<Deck> d1 (new Deck());
    Hand = p.nextCard();
    d1->push(Hand);
    h.addHydraHead(d1);
    std::shared_ptr<Deck> d2 (new Deck());
    Hand = p.nextCard();
    d2->push(Hand);
    h.addHydraHead(d2);
}
