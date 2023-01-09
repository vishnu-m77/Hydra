#include "theGame.h"
#include <iostream>
#include <memory>

theGame::theGame(int no_players, int cards, bool test) {
    no_of_players = no_players;
    cards_per_player = cards;
    testing = test;
    Deck Superdeck;
    for (int i = 0; i < no_of_players; ++i) {
        for (int j = 0; j < no_of_suits; ++j) {
            char suit = ' ';
            switch(j) {
                case 0:
                    suit = 'C';
                    break;
                case 1:
                    suit = 'D';
                    break;
                case 2:
                    suit = 'H';
                    break;
                case 3:
                    suit = 'S';
                    break;
                default:
                    break;
            }
            for (int k = 1; k <= no_of_values; ++k) {
                std::shared_ptr<Card> c(new Card(k, suit));
                Superdeck.push(c);
            }
        }
        std::shared_ptr<Card> j (new Card(2, 'J'));
        Superdeck.push(j);
        Superdeck.push(j);
    }
    // std::cout << Superdeck.size() << std::endl;
    Superdeck.shuffle();
    for (int i = 0; i < no_of_players; ++i) {
        std::shared_ptr<Deck> draw (new Deck());
        std::shared_ptr<Deck> discard (new Deck());
        for (int k = 0; k < cards_per_player; ++k) {
            std::shared_ptr<Card> c = std::move(Superdeck.back());
            draw->push(c);
            Superdeck.pop();
        }
        // std::cout << "Works at 1" << std::endl;
        std::shared_ptr<Player> p1 (new Player(draw, discard));
        p.addPlayer(p1);
        // std::cout << "Works at 2" << std::endl;
    }
    // Initialize game
    std::shared_ptr<Card> c;
    c = p.nextCard();
    std::shared_ptr<Deck> d (new Deck());
    // std::cout << "Works at 3" << std::endl;
    d->push(c);
    // std::cout << "Works at 4" << std::endl;
    h.addHydraHead(d);
    // std::cout << "Works at 5" << std::endl;
    p.incPlayer();
    // std::cout << "Works at 6" << std::endl;
    begin();
}

theGame::~theGame() {};

void theGame::begin() {
    int win = 0;
    while(1) {
        // std::cout << "Works at 7" << std::endl;
        printHead(h);
        // std::cout << "Works at 8" << std::endl;
        printPlayer(p);
        Turn t(testing);
        // std::cout << "Works at 9" << std::endl;
        win = t.next(p, h);
        // std::cout << "Works at 10" << std::endl;
        if (win == 1) {
            printWin(p.curr_player());
            break;
        }
        if (win == -1) {
            break;
        }
        p.incPlayer();
    }
}



