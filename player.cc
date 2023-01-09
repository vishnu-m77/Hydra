#include "player.h"
#include <iostream>

Player::Player(std::shared_ptr<Deck> Draw, std::shared_ptr<Deck> Discard) : DrawPile{Draw}, DiscardPile{Discard} {};

int Player::count() {
    int count = 0;
    count += DrawPile->size();
    count += DiscardPile->size();
    return count;
}

bool Player::isEmpty() {
    return DrawPile->isEmpty()&&DiscardPile->isEmpty();
}

bool Player::DrawPileIsEmpty() {
    return DrawPile->isEmpty();
}

void Player::RecreateDrawPile() {
    int sizePile = DiscardPile->size();
    for (int i = 0; i < sizePile; ++i) {
        DrawPile->push(DiscardPile->back());
        DiscardPile->pop();
    }
    DrawPile->shuffle();
}

std::shared_ptr<Card> Player::nextCard() {
    if (DrawPileIsEmpty()) {
        RecreateDrawPile();
    }
    std::shared_ptr<Card> c;
    c = DrawPile->back();
    DrawPile->pop();
    return c;
}

void Player::addToDiscard(std::shared_ptr<Card> c) {
    char suit = c->getSuit();
    if (suit=='J') {
        c->reset();
        DiscardPile->push(c);
        return;
    }
    DiscardPile->push(c);
}

void Player::addToDiscard(std::shared_ptr<Deck> d) {
    if (d->isEmpty()) {
        return;
    }
    int length = d->size();
    for ( int i = 0; i < length; ++i) {
        std::shared_ptr<Card> c = d->back();
        char suit = c->getSuit();
        if (suit=='J') {
            c->reset();
            DiscardPile->push(c);
            d->pop();
            return;
        }
        DiscardPile->push(c);
        d->pop();
    }
}

int Player::sizeDraw() {
    return DrawPile->size();
}

int Player::sizeDiscard() {
    return DiscardPile->size();
}


