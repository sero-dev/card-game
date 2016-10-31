/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Card.cpp
 * Purpose: Creates a card object that holds a rank, suit, and value 
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 21, 2016
 * @version 1.0
 */

#include <iostream>
#include "Card.h"

// Initialize Rank and Suit arrays
std::string Card::rankAsStr[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8","9", "10", "Jack", "Queen", "King" };
std::string Card::suitAsStr[4] = { "Spade", "Heart", "Club", "Diamond" };

/**
 * Default Constructor
 */
Card::Card() {
	rank = 0;
	suit = 0;
}

/**
 * Initializes rank and suit
 *
 * @param rank of the card
 * @param suit of the card
 */
Card::Card(int r, int s) {
	rank = r;
	suit = s;
	value = r + 1;
}

/**
 * Initializes rank, suit and value
 *
 * @param rank of the card
 * @param suit of the card
 * @param value of the card
 */
Card::Card(int r, int s, int v) {
	rank = r;
	suit = s;
	value = v;
}

/**
 * Mutator Methods
 */
void Card::setRank(int r) {rank = r;}
void Card::setSuit(int s) {suit = s;}
void Card::setValue(int v) {value = v;}

/**
 * Accessor Methods
 */
int Card::getRank() const {return rank;}
int Card::getSuit() const {return suit;}
int Card::getValue() const {return value;}

/**
 * Overloads operators to add/subtract the values
 */
int Card::operator+(const Card& a) const {return value + a.value;}
int Card::operator-(const Card& a) const {return (value < a.value) ? a.value - value : value - a.value;}

/** 
 * Overloads operators to compare Cards' values
 */
bool Card::operator<(const Card& a) const {return value < a.value;}
bool Card::operator>(const Card& a) const {return value > a.value;}
bool Card::operator==(const Card& a) const {return value == a.value;}
bool Card::operator!=(const Card& a) const {return value != a.value;}
bool Card::operator<=(const Card& a) const {return value <= a.value;}
bool Card::operator>=(const Card& a) const {return value >= a.value;}

bool Card::operator^(const Card& a) const {return suit == a.suit;}	// Checks if suits are the same


/**
 * Returns Card information
 *
 * @return the card information as a string
 */
std::string Card::toString() const {
	return rankAsStr[rank] + " of " + suitAsStr[suit];
}

/**
 * Prints out a card information
 */
void Card::display() const {
	std::cout << rankAsStr[rank] << " of " << suitAsStr[suit] << std::endl;
}