/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Deck.cpp
 * Purpose: Creates a stack of Card* to represent a deck
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 21, 2016
 * @version 1.0
 */

#include <ctime>
#include <cstdlib>
#include "Deck.h"

/**
 * Initializes deck
 */
Deck::Deck() {
	deck = new Stack(52);					// Creates a stack of 52

	for(int i = 0; i < 4; i++)				// For every suit...
		for(int j = 0; j < 13; j++)			// ... of every rank... 
			deck->push(new Card(j, i));		// ... add a card of each to the deck
}

/**
 * De-Constructor: Destroys all dynamic variables
 */
Deck::~Deck() {
	delete deck;
}

/**
 * Deals the top card OUT of the deck
 *
 * @return top card of the deck
 */
Card* Deck::deal() {
	return deck->pop();
}

/**
 * Place a card IN the deck
 *
 * @param the address of a card
 * @return the deck
 */
Deck* Deck::placeBack(Card* c) {
	deck->push(c);
	return this;
}

/**
 * Shuffles the deck
 * 
 * @return the deck
 */
Deck* Deck::shuffle() {
	Card* c[52];								// Creates an array for 52 card pointers

	for (int i = 0; i < 52; i++)				// Iterate through the array...
		c[i] = deck->pop();						// ...Pop out cards from Deck stack, populating the array

	srand((unsigned int)time(NULL));			// Start random generator

	for (int i = 0; i < 1000; i++)				// Iterate 1000 times
		swap(c[rand() % 52], c[rand() % 52]);	// Swap two random pointer locations

	for (int i = 0; i < 52; i++)				// Iterate through randomized array
		deck->push(c[i]);						// ...Push cards back into the Deck stack 

	return this;
}

/** 
 * Swap pointer locations
 */
void Deck::swap(Card* a, Card* b) {
	Card temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * Displays the deck from top to bottom
 */
void Deck::display() const {
	deck->display();
}