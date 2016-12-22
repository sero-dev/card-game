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

#include "Card.h"
#include "Stack.h"

const int DEFAULT_DECK_SIZE = 52;

class Deck {
	friend std::ostream& operator<<(std::ostream&, const Deck&);

private:	
	Stack<Card*> * deck;
	void swap(Card*, Card*);	// Swaps pointer locations
	
public:
	Deck();						// Default Constructor

	~Deck();						// Destructor
	Deck(const Deck&);				// Copy constructor
	Deck operator=(const Deck&);	// Overloaded Assignment Operator
	
	Deck* shuffle();			// Shuffles deck
	Card* deal();				// Deals the top card of the deck
	Deck* placeBack(Card*);		// Places a card at the top of the deck
	
	Stack<Card*> getDeck() const;
};

#endif

