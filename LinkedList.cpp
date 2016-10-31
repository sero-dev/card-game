/**
 * CUNY Queens College - CS211 | CardGame
 * Name: LinkedList.cpp
 * Purpose: Creates dynamic data structure that is Node-Base
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 31, 2016
 * @version 1.0
 */

#include <iostream>
#include "LinkedList.h"

/**
 * Initializes the size and head variables
 */
LinkedList::LinkedList() {
	size = 0;	// Sets size to 0
	head = 0;	// Points head to nothing
}

/**
 * Deletes the whole list
 */
LinkedList::~LinkedList() {
	while (size != 0) {
		delete get(size - 1);
		size--;
	}
}

/**
 * Adds a node to the beginning of the list
 *
 * @param value of data in the Node to be added
 */
void LinkedList::add(Card* card) {
	Node* number = new Node(card);		// Creates a new node object

	if (head != 0) {				// If head points to something...
		number->next = head;		// ... set the new node's next to whatever head points to
	}

	head = number;					// Point the head to the new node
	size++;							// Increase the size by one
}

int LinkedList::addAll() const{
	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += get(i)->card->getValue();

	return sum;
}

/**
 * Removes the node in the beginning of the list
 */
Card* LinkedList::remove() {
	if (size == 0) return NULL;		// If there is nothing in the list, return

	Node* temp = head;				// To delete dynamic variable
	head = head->next;				// Set the head to next

	size--;							// Decrease the size by 1
	return temp->card;				// Return removed Node
}

/**
 * Removes a node from a specified index
 *
 * @param index where Node is stored
 */
Card* LinkedList::remove(int index) {
	if (index > size - 1) index = size - 1;		// Catches upper-bound violations
	if (index < 0) index = 0;					// Catches lower-bound violations

	if (index == 0) remove();					// If index = 0, call remove function
	else {										// Else...
		Node* temp = get(index);				// Create pointer to Node index
		Node* itr = get(index - 1);				// Create pointer before index
		itr->next = itr->next->next;			// Set before pointer's next to a Node, two indices ahead
		
		size--;									// Decrease size by 1
		return temp->card;						// Return removed Node
	}
}

/**
 * Gets the node at specified index
 *
 * @param index where Node is stored
 * @return the Node request from the parameter
 */
Node* LinkedList::get(int index) const{
	if (index > size - 1) index = size - 1;		// Catches upper-bound violations
	if (index < 0) index = 0;					// Catches lower-bound violations

	Node* itr = head;							// Set iterator to the head of the list
	for (int i = 1; i <= index; i++)			// Iterator 'index' times if index is not 0
		itr = itr->next;						// Move iterator one up in the list

	return itr;									// Return the iterator
}

/**
 * Displays the whole list from front to back
 */
void LinkedList::display() {
	if (size == 0) return;							// If size = 0, return

	for (int i = 0; i < size; i++)					// For each index...
		std::cout << get(i)->card->toString()		// ... print out its data
		<< std::endl;		
	std::cout << std::endl;							// End the line afterwards
}

// Operator Overloads
bool LinkedList::operator>(const LinkedList& rhs) const { return addAll() > rhs.addAll(); }
bool LinkedList::operator<(const LinkedList& rhs) const { return addAll() < rhs.addAll(); }
bool LinkedList::operator==(const LinkedList& rhs) const { return addAll() == rhs.addAll(); }
bool LinkedList::operator!=(const LinkedList& rhs) const { return addAll() != rhs.addAll(); }

