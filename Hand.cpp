/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Hand.cpp
 * Purpose: Using LinkedList class, to implement a player's hand
 *
 * @author Sean Rodriguez <sean.rodriguez@outlook.com>
 * @copyright Sean Rodriguez December 25, 2016
 * @version 1.0
 */

#include "Hand.h"
#include <iostream>

// Default Constructor
Hand::Hand() : hand(new LinkedList()) {}

// Copy Constructor
Hand::Hand(Hand& copy) {
	for (int i = 0; i < hand->getSize(); i++) {
		copy.hand->insertAtIndex((*hand)[i], 0);
	}
}

// Overloaded = operator
Hand& Hand::operator=(Hand& copy) {
	delete copy.hand;
	copy.hand = new LinkedList();
	for (int i = 0; i < hand->getSize(); i++) {
		copy.hand->insertAtIndex((*hand)[i], 0);
	}

	return *this;
}

// Destructor
Hand::~Hand() { delete hand; }

// Gets number of cards in hand
int Hand::getCount() const {
	return hand->getSize();
}

// Inserts card by rank
void Hand::insertByRank(Card* card) {
	for (int i = 0; i < hand->getSize(); i++)
		if (card->getRank() < hand->getAtIndex(i)->getRank()) {
			hand->insertAtIndex(card, i);
			break;
		}
}

// Inserts card at the back of the hand
void Hand::insertLast(Card* card) {
	hand->insertAtIndex(card, hand->getSize());
}

// Removes the card in front of the hand
Card* Hand::remove() {
	return hand->removeAtIndex(0);
}

// Evaluates the value of the hand
int Hand::evaluate() const {
	int sum = 0;

	for (int i = 0; i < hand->getSize(); i++)
		sum += (*hand)[i]->getValue();

	return sum;
}

// Converts all Ace values to 1
void Hand::convertAcesDown() {
	for (int i = 0; i < hand->getSize(); i++) {
		if ((*hand)[i]->getRank() == 1)
			(*hand)[i]->setValue(1);
	}
}

// Compares on hand value to another
int Hand::compare(const Hand& other) {
	if (evaluate() == other.evaluate()) return 0;
	else if (evaluate() > other.evaluate()) return 1;
	else return -1;
}

// Checks if hand is empty
bool Hand::isEmpty() {
	return hand->isEmpty();
}

// Dealer hand; does not show first card
void Hand::currentHand() const {
	for (int i = 1; i < getCount(); i++)
		std::cout << *(*hand)[i] << std::endl;
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Hand& hand) {
	os << *(hand.hand);
	return os;
}
