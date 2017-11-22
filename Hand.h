/**
 * CUNY Queens College - CS211 | CardGame 
 * Name: Hand.h
 * Purpose: Using LinkedList class, to implement a player's hand
 *
 * @author Sean Rodriguez <sean.rodriguez@outlook.com>
 * @copyright Sean Rodriguez December 25, 2016
 * @version 1.0
 */

#ifndef HAND_H
#define HAND_H

#include "LinkedList.h"

class Hand {

	// Overloaded << operator
	friend std::ostream& operator<<(std::ostream& os, const Hand& hand);

private:
	LinkedList* hand;	// LinkedList hand object

public:
	Hand();							// Default Constructor
	Hand(Hand& copy);				// Copy Constructor
	Hand& operator=(Hand& copy);	// Overloaded = operator
	~Hand();						// Destructor

	int getCount() const;				// Gets number of cards
	
	void insertByRank(Card* card);		// Inserts card by rank
	void insertLast(Card* card);		// Inserts card last
	
	Card* remove();						// Removes card from the front
	int evaluate() const;				// Evaluates the value of the hand
	void convertAcesDown();				// Converts all Ace values to 1
	
	int compare(const Hand& other);		// Compares one hand to another
	bool isEmpty();						// Checks if hand is empty

	void currentHand() const;			// Dealer hand; does not show first card
};

#endif
