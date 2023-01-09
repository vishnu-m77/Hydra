#include "card.h"
#include <string>

Card::Card(int value, char suit) : value{value}, suit{suit} {};

Card::~Card() {};

std::string Card::name() {
    std::string returnString = "";
    std::string val = "";
    switch (value) {
        case 1 : 
            val = "A";
            break;
        case 11 : 
            val = "J";
            break;
        case 12 : 
            val = "Q";
            break;
        case 13 : 
            val = "K";
            break;
        default : 
            val = std::to_string(value);
    }
    returnString.append(val);
    std::string s(1,suit);
    returnString.append(s);
    return returnString;
}

int Card::getValue() {
    return value;
}

char Card::getSuit() {
    return suit;
}

void Card::setValue(int val) {
    if (suit != 'J') {
        return;
    }
    value = val;
}

void Card::reset() {
    if (suit != 'J') {
        return;
    }
    value = 2;
}
