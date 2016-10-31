/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Player.h
 * Purpose: Models the attributes of a player in a card game
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 31, 2016
 * @version 1.0
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "LinkedList.h"
#include "Card.h"

class Player {
private:
	std::string name;
	double cash;
	LinkedList hand;

public:
	Player(std::string, double);
	
	std::string getName();
	double getCash();

	void hit(Card*);
	Card* removeCard(int);
	
	void displayHand();
	
	bool operator>(const Player&) const;
	bool operator<(const Player&) const;
	bool operator==(const Player&) const;
	bool operator!=(const Player&) const;
};

#endif