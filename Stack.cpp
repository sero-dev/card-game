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

using namespace std;

// Default Constructor
Stack::Stack(int capacity)
{
	this->capacity = capacity;
	stack = new Card*[this->capacity];
	size = 0;
}

// Deconstructor: Destroys all dynamic variables
Stack::~Stack() {
	delete[] stack;
}


/**
	Pushes Card* to the end of the array
	
	@param a object of type Card* to insert at the end of the array
	@return a pointer pointing to this Stack
*/
Stack* Stack::push(Card* c) {
	if (isFull())
		cout << "Error: Capacity full" << endl;
	else {
		stack[size++] = c;
	}

	return this;
}


/**
	Pops the last Card* added to the array; exits if array is empty

	@return the Card* that was popped out 
*/
Card* Stack::pop() {
	if (isEmpty()) {
		cout << "Error: Stack is empty." << endl;
		exit(-1);
	}

	return stack[--size];
}


/**
	Returns the last Card* added to the array; exits if array is empty

	@return the Card* that was last added to the array
*/
Card* Stack::peep() {
	if (isEmpty()) {
		cout << "Error: Stack is empty." << endl;
		exit(-1);
	}

	return stack[size - 1];
}

void Stack::display() {
	if (isEmpty()) return;

	for (int i = size - 1; i >= 0; i--)
		stack[i]->display();
}

bool Stack::isEmpty() {
	return size == 0;
}

bool Stack::isFull() {
	return size == capacity;
}