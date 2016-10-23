/**
	CUNY Queens College - CS211 | CardGame
	Name:		Card.h
	Purpose:	Creates a card object that holds a rank, suit, and value 

	@author		Sean Rodriguez <sean.rodriguez@gmail.com>
	@copyright	Sean Rodriguez October 21, 2016
	@version	1.0 
*/

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {

private:
	static string rankAsStr[13];	// = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10" "Jack", "Queen", "King" };
	static string suitAsStr[4];		// = { "Spade", "Heart", "Club", "Diamond" };
	
	int rank;
	int suit;
	int value;

public:
	Card();					// Default Constructor
	Card(int,int);			// Constructor defaults value
	Card(int,int,int);		// Constructor sets all variables
	
	// Mutator Functions
	void setRank(int);
	void setSuit(int);
	void setValue(int);
	
	// Accessor Functions
	int getRank();
	int getSuit();
	int getValue();
	
	
	int operator+(const Card&);		// Adds values together
	int operator-(const Card&);		// Finds the difference between the values

	bool operator>(const Card&);	// Checks if value is greater than
	bool operator<(const Card&);	// Checks if value is less than
	bool operator>=(const Card&);	// Checks if values are greater or equal to 
	bool operator<=(const Card&);	// Checks if values are less or equal to
	bool operator==(const Card&);	// Checks if values are the same
	bool operator!=(const Card&);	// Checks if values are NOT the same
	bool operator^(const Card&);	// Checks for same suit

	string toString();		// Returns Card information
	void display();			// Displays Card information
};



#endif