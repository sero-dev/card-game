/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Stack.h
 * Purpose: Creates a data structure that mimics the Standard Stack class
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 21, 2016
 * @version 1.0
 */

#ifndef STACK_H
#define STACK_H

#include <string>
#include "Card.h"

class Stack {

private:
	Card** stack;		// Points to Card* array
	int size;			// Number of items in array
	int capacity;		// Max capacity of array
	
	bool isFull() const;		// Checks if array is full
	bool isEmpty() const;		// Checks if array is empty

public:
	Stack(int);			// Initializes all member variables
	~Stack();			// Destroys all dynamic variables

	Stack* push(Card*);		// Pushs Card* at the end
	Card* pop();			// Removes Card* at the end
	Card* peep() const;		// Views Card* at the end

	void display() const;		// Displays Stack from Top to Bottom
};

#endif
