/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Deck.h
 * Purpose: Creates a stack of Card* to represent a deck
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 21, 2016
 * @version 1.0
 */

#ifndef DECK_H
#define DECK_H

#include "Stack.h"

class Deck {
private:	
	Stack* deck;
	void swap(Card*, Card*);	// Swaps pointer locations
	
public:
	Deck();						// Default Constructor
	~Deck();					// Destroys all dymanic variables
	
	Deck* shuffle();			// Shuffles deck
	Card* deal();				// Deals the top card of the deck
	Deck* placeBack(Card*);		// Places a card at the top of the deck
	
	void display();				// Displays the deck from top to bottom
};

#endif

