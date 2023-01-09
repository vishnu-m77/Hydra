#ifndef __CARD_H__
#define __CARD_H__
#include <string>

class Card {
    int value;
    char suit;
public:
    Card(int value, char suit);
    virtual ~Card();
    std::string name();
    int getValue();
    char getSuit();
    void setValue(int val);
    void reset();
};

#endif
