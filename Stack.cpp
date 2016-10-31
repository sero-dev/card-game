/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Stack.cpp
 * Purpose: Creates a data structure that mimics the Standard Stack class
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 21, 2016
 * @version 1.0
 */

#include <iostream>
#include "Stack.h"
#include "Card.h"

/**
 * Initializes all member variables
 *
 * @param size of the data structure
 */
Stack::Stack(int capacity) {
	this->capacity = capacity;				// Set the capacity
	stack = new Card*[this->capacity];		// Create an array of Card* with a size of 'capacity' 
	size = 0;								// Set size to 0
}

/** 
 * Destroys all dynamic variables
 */
Stack::~Stack() {
	delete[] stack;							// Deletes dynamic array
}


/**
 * Pushes Card* to the end of the array
 *	
 * @param a object of type Card* to insert at the end of the array
 * @return a pointer pointing to this Stack
 */
Stack* Stack::push(Card* c) {
	if (isFull())												// Checks if stack is full...
		std::cout << "Error: Capacity full" << std::endl;		// ... displays error message
	else {
		stack[size++] = c;										// Add Card* to stack
	}

	return this;												// Return this Deck
}


/**
	Pops the last Card* added to the array; exits if array is empty

	@return the Card* that was popped out 
*/
Card* Stack::pop() {
	if (isEmpty()) {											// Checks if stack is empty...
		std::cout << "Error: Stack is empty." << std::endl;		// ... displays error message... 
		exit(-1);												// ... exits program
	}

	return stack[--size];										// Decreases size by 1, return the top index
}


/**
	Returns the last Card* added to the array; exits if array is empty

	@return the Card* that was last added to the array
*/
Card* Stack::peep() const {
	if (isEmpty()) {											// Checks if stack is empty...
		std::cout << "Error: Stack is empty." << std::endl;		// ... displays error message...
		exit(-1);												// ... exits program
	}

	return stack[size - 1];										// Returns the top index
}

/**
 * Displays structure from top to bottom
 */
void Stack::display() const {
	if (isEmpty()) return;	// Returns nothing if it is empty

	for (int i = size - 1; i >= 0; i--)		// For every index...
		stack[i]->display();				// ... display its information
}

/**
 * Checks if stack is empty
 *
 *	@return if it is empty or not
 */
bool Stack::isEmpty() const {
	return size == 0;
}

/**
 * Checks if stack is full
 *
 * @return if it is full or not
 */
bool Stack::isFull() const {
	return size == capacity;
}