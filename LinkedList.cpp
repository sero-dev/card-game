/**
 * CUNY Queens College - CS211 | CardGame
 * Name: LinkedList.cpp
 * Purpose: Creates dynamic data structure that is Node-Base
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 24, 2016
 * @version 1.0
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

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
	while (size != 0)
		remove();
}

/**
 * Adds a node to the beginning of the list
 *
 * @param value of data in the Node to be added
 */
void LinkedList::add(int n) {
	Node* number = new Node(n);		// Creates a new node object

	if (head != 0) {				// If head points to something...
		number->next = head;		// ... set the new node's next to whatever head points to
	}

	head = number;					// Point the head to the new node
	size++;							// Increase the size by one
}

/**
 * Removes the node in the beginning of the list
 */
void LinkedList::remove() {
	if (size == 0) return;		// If there is nothing in the list, return

	Node* deleteNode = head;	// To delete dynamic variable
	head = head->next;			// Set the head to next

	delete deleteNode;			// Deletes dynamic variable
	size--;						// Decrease the size by 1
}

/**
 * Removes a node from a specified index
 *
 * @param index where Node is stored
 */
void LinkedList::remove(int index) {
	if (index > size - 1) index = size - 1;		// Catches upper-bound violations
	if (index < 0) index = 0;					// Catches lower-bound violations

	if (index == 0) remove();					// If index = 0, call remove function
	else {										// Else...
		Node* deleteNode = get(index);			// Create pointer to Node index
		Node* itr = get(index - 1);			// Create pointer before index
		itr->next = itr->next->next;			// Set before pointer's next to a Node, two indices ahead
		
		delete deleteNode;						// Delete dynamic Node
		size--;									// Decrease size by 1
	}
}

/**
 * Gets the node at specified index
 *
 * @param index where Node is stored
 * @return the Node request from the parameter
 */
Node* LinkedList::get(int index) {
	if (index > size - 1) index = size - 1;		// Catches upper-bound violations
	if (index < 0) index = 0;					// Catches lower-bound violations

	Node* itr = head;							// Set iterator to the head of the list
	for (int i = 1; i <= index; i++)			// Iterator 'index' times if index is not 0
		itr = itr->next;						// Move iterator one up in the list

	return itr;								// Return the iterator
}

/**
 * Displays the whole list from front to back
 */
void LinkedList::display() {
	if (size == 0) return;					// If size = 0, return

	for (int i = 0; i < size; i++)			// For each index...
		std::cout << get(i)->data << " ";	// ... print out its data followed by a space
	std::cout << std::endl;					// End the line afterwards
}

