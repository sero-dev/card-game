/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Card.h
 * Purpose: Creates a card object that holds a rank, suit, and value
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 21, 2016
 * @version 1.0
 */

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {

private:
	static std::string rankAsStr[13];	// = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10" "Jack", "Queen", "King" };
	static std::string suitAsStr[4];		// = { "Spade", "Heart", "Club", "Diamond" };
	
	int rank;
	int suit;
	int value;

public:
	Card();					// Default Constructor
	Card(int,int);			// Initializes rank and suit 
	Card(int,int,int);		// Initializes rank, suit and value
	
	// Mutator Functions
	void setRank(int);
	void setSuit(int);
	void setValue(int);
	
	// Accessor Functions
	int getRank() const;
	int getSuit() const;
	int getValue() const;
	
	
	int operator+(const Card&) const;		// Adds values together
	int operator-(const Card&) const;		// Finds the difference between the values

	bool operator>(const Card&) const;		// Checks if value is greater than
	bool operator<(const Card&) const;		// Checks if value is less than
	bool operator>=(const Card&) const;		// Checks if values are greater or equal to 
	bool operator<=(const Card&) const;		// Checks if values are less or equal to
	bool operator==(const Card&) const;		// Checks if values are the same
	bool operator!=(const Card&) const;		// Checks if values are NOT the same
	bool operator^(const Card&) const;		// Checks for same suit

	std::string toString() const;		// Returns Card information
	void display() const;				// Displays Card information
};



#endif