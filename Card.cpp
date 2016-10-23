/**
	CUNY Queens College - CS211 | CardGame
	Name:		Card.cpp
	Purpose:	Creates a card object that holds a rank, suit, and value

	@author		Sean Rodriguez <sean.rodriguez@gmail.com>
	@copyright	Sean Rodriguez October 21, 2016
	@version	1.0 
*/

#include <iostream>
#include "Card.h"

using namespace std;

// Initialize Rank and Suit arrays
string Card::rankAsStr[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8","9", "10", "Jack", "Queen", "King" };
string Card::suitAsStr[4] = { "Spade", "Heart", "Club", "Diamond" };

// Default Constructor
Card::Card() {
	rank = 0;
	suit = 0;
}

// Constructor defaults value
Card::Card(int r, int s) {
	rank = r;
	suit = s;
	value = r + 1;
}

// Constructor sets all variables
Card::Card(int r, int s, int v) {
	rank = r;
	suit = s;
	value = v;
}

// Variable Mutator/Accessor Methods
void Card::setRank(int r) {rank = r;}
void Card::setSuit(int s) {suit = s;}
void Card::setValue(int v) {value = v;}
int Card::getRank() {return rank;}
int Card::getSuit() {return suit;}
int Card::getValue() {return value;}

// Overloads operators to add/subtract the values
int Card::operator+(const Card& a) {return value + a.value;}
int Card::operator-(const Card& a) {return (value < a.value) ? a.value - value : value - a.value;}

// Overloads operators to compare Cards' values
bool Card::operator<(const Card& a) {return value < a.value;}
bool Card::operator>(const Card& a) {return value > a.value;}
bool Card::operator==(const Card& a) {return value == a.value;}
bool Card::operator!=(const Card& a) {return value != a.value;}
bool Card::operator<=(const Card& a) {return value <= a.value;}
bool Card::operator>=(const Card& a) {return value >= a.value;}

bool Card::operator^(const Card& a) {return suit == a.suit;}	// Checks if suits are the same


// Returns [RANK] of [SUIT]
string Card::toString() {
	return rankAsStr[rank] + " of " + suitAsStr[suit];
}

// Output [RANK] of [SUIT]
void Card::display() {
	cout << rankAsStr[rank] << " of " << suitAsStr[suit] << endl;
}