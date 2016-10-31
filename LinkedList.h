/**
 * CUNY Queens College - CS211 | CardGame
 * Name: LinkedList.h
 * Purpose: Creates dynamic data structure that is Node-Base
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 31, 2016
 * @version 1.0
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {

private:
	int size;				// Holds the size of the list
	Node* head;				// Points to the beginning of the list
	Node* get(int) const;	// Gets the node at specified index

public:
	LinkedList();
	~LinkedList();
	
	void add(Card*);	// Adds a node to the beginning of the list
	Card* remove();		// Removes the node in the beginning of the list
	Card* remove(int);	// Removes a node from a specified index

	int addAll() const;		// Adds value of all cards inside the list
	
	// Operator Overloads
	bool operator>(const LinkedList&) const;
	bool operator<(const LinkedList&) const;
	bool operator==(const LinkedList&) const;
	bool operator!=(const LinkedList&) const;

	void display();		// Displays the whole list from front to back
};

#endif

