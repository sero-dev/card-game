/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Player.h
 * Purpose: Implements functionality for a player, including name, hand & points
 *
 * @author Sean Rodriguez <sean.rodriguez@outlook.com>
 * @copyright Sean Rodriguez December 27, 2016
 * @version 1.0
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"

class Player {

	// Overloaded << operator
	friend std::ostream& operator<<(std::ostream& os, const Player& player);

private:
	std::string name;	// Name of player
	Hand hand;			// Player's hand
	int points;			// Player's points

public:
	Player();							// Default Constructor
	Player(std::string name);			// Constructor for name
			
	void setName(std::string name);		// Sets Player's name
	std::string getName() const;		// Gets Player's name

	void addCard(Card*);				// Adds card to hand
	void addPoints(int points);			// Adds points to player
	Card* remove();						// Removes card in front of hand
	int evaluate() const;				// Evaluates value of hand

	int getPoints() const;				// Gets total points
	int getNumberOfCards() const;		// Gets number of cards in hand

	void currentHand() const;			// Dealer's hand; does not show first card
	void showHand() const;				// Shows player's entire hand
};

#endif
