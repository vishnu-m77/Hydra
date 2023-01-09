#include "deck.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>

Deck::Deck() {};

bool Deck::isEmpty() {
    bool b = false;
    if (SetOfCards.empty()) {
        b = true;
    }
    return b;
}

std::shared_ptr<Card> Deck::back() {
    return SetOfCards.back();
}

void Deck::pop() {
    if (isEmpty()) {
        return;
    }
    SetOfCards.pop_back();
}

void Deck::push(std::shared_ptr<Card> c) {
    std::shared_ptr<Card> temp = c;
    SetOfCards.push_back(temp);
}

void Deck::shuffle() {
    if (isEmpty()) {
        return;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (SetOfCards.begin(), SetOfCards.end(), std::default_random_engine(seed));
}

int Deck::size() {
    return SetOfCards.size();
}


