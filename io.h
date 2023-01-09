#ifndef __IO_H__
#define __IO_H__

#include "card.h"
#include "deck.h"
#include "player.h"
#include "players.h"
#include "hydra.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

void printTurn(int player_no);

int getMove(std::shared_ptr<Card> Hand, int player_no);

void printHead(Hydra & h);

int getJoker();

void printWin(int player_no);


void printMove(Hydra &h, Players & p, bool reserve, int no_of_moves_rem);
/*
//prints only 1 player 
// Probably not needed, use printPlayer
void printMove(std::shared_ptr<Player> p);
*/
void printPlayer(Players & p);

std::shared_ptr<Card> getCard();


#endif