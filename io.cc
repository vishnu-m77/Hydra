#include "io.h"


void printTurn(int player_no) {
    while(1) {
        std::cout << "Player " << player_no << ", it is your turn." << std::endl;
        std::cout << " Press ENTER to continue. ";
        std::cout << std::endl;
        std::string s;
        getline(std::cin, s );
        if (std::cin.fail()) {
            s = "";
            return;
        }
        if (s=="") {
            break;
        }
    }
}

int getMove( std::shared_ptr<Card> Hand, int player_no) {
    int i = -1;
    while(1) {
        std::cout << "Player " << player_no << ", you are holding a ";
        if (Hand->getSuit() == 'J') {
            std::cout << "Joker";
        } else {
            std::cout << Hand->name();
        }
        std::cout << ". Your move?" << std::endl; 
        std::string s;
        getline( std::cin, s );
        if (std::cin.fail()) {
            s = "-1";
            break;
        }
        try {
         i = std::stoi(s);
         if (i==-1) {
             continue;
          }
        } catch (...) {
            continue;
        }
        break;
    }
    return i;
}

void printHead(Hydra &h) {
    std::cout << h;
}

int getJoker() {
    int i = 0;
    while(1) {
        i = 0;
        char c = '0';
        std::cout << "Joker value?" << std::endl;
        std::cout << "(Please enter one of the following: 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K')" << std::endl;
        std::string s;
        getline( std::cin, s );
        if (std::cin.fail()) {
            s = "";
            break;
        }
        try {
         i = std::stoi(s);
        } catch (...) {
            if (s.length() > 1) {
                continue;
            }
            try { 
            c = s[0];
            } catch (...) {
                continue;
            }
        }
        if (i == 0) {
            switch(c) {
                case 'A' :
                    i = 1;
                    break;
                case 'J' :
                    i = 11;
                    break;
                case 'Q':
                    i = 12;
                    break;
                case 'K':
                    i = 13;
                    break;
                default : continue;
            }
        }
        break;
    }
    return i;
}

void printWin(int player_no) {
    std::cout << "Player " << player_no << " wins!" << std::endl;
}

void printMove(Hydra &h, Players & p, bool reserve, int no_of_moves_rem) {
    std::cout << h;
    p.print(reserve, no_of_moves_rem);
}


void printPlayer(Players & p) {
    std::cout << p;
}

std::shared_ptr<Card> getCard() {
    int i = 0;
    char d = '0';
    while (1) {
        d = '0';
        std::cout << "Card suit?" << std::endl;
        std::cout << "(Please enter one of the following: 'C', 'D', 'H', 'S', \"Joker\")" << std::endl;
        std::string s;
        getline( std::cin, s );
        if (std::cin.fail()) {
            s = "";
            break;
        }
        try { 
            d = s[0];
        } catch (...) {
            continue;
        }
        if (d == 'J') {
            if (s == "Joker") {
                break;
            } else {
                continue;
            }
        }
        if ( d != 'C' && d != 'D' && d != 'H' && d != 'S' ) {
            continue;
        }
        break;
    }
    if (d == 'J') {
        i = 2;
    }
    while(1) {
        if (i != 0) {
            break;
        }
        i = 0;
        char c = '0';
        std::cout << "Card value?" << std::endl;
        std::cout << "(Please enter one of the following: 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K')" << std::endl;
        std::string s;
        getline( std::cin, s );
        if (std::cin.fail()) {
            s = "";
            break;
        }
        try {
         i = std::stoi(s);
        } catch (...) {
            if (s.length() > 1) {
                continue;
            }
            try { 
            c = s[0];
            } catch (...) {
                continue;
            }
        }
        if (i == 0) {
            switch(c) {
                case 'A' :
                    i = 1;
                    break;
                case 'J' :
                    i = 11;
                    break;
                case 'Q':
                    i = 12;
                    break;
                case 'K':
                    i = 13;
                    break;
                default : continue;
            }
        }
        break;
    }
    std::shared_ptr<Card> c (new Card(i, d));
    return c;
}
    



