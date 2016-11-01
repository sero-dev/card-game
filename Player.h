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
	std::string name;	// Player's name
	double cash;		// Player's cash
	LinkedList hand;	// Player's hand

public:
	Player(std::string, double);	// Initializes name and cash
	
	std::string getName();			// Gets player's name
	double getCash();				// Gets player's cash

	void hit(Card*);				// Puts one card in player's hand
	Card* removeCard(int);			// Removes one specified card from player's hand
	
	void displayHand();				// Displays player's hand
	
	// Operator Overloading, compares total value of player's hand
	bool operator>(const Player&) const;
	bool operator<(const Player&) const;
	bool operator==(const Player&) const;
	bool operator!=(const Player&) const;
};

#endif