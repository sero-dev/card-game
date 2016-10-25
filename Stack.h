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
	
	bool isFull();		// Checks if array is full
	bool isEmpty();		// Checks if array is empty

public:
	Stack(int);			// Takes in the capacity for the array
	~Stack();			// Destroys all dynamic variables

	Stack* push(Card*);		// Pushs Card* at the end
	Card* pop();			// Removes Card* at the end
	Card* peep();			// Views Card* at the end

	void display();		// Displays Stack from Top to Bottom
};

#endif
