/**
* CUNY Queens College - CS211 | CardGame
* Name: LinkedList.h
* Purpose: Creates dynamic data structure that is Node-Base
*
* @author Sean Rodriguez <sean.rodriguez@gmail.com>
* @copyright Sean Rodriguez October 24, 2016
* @version 1.0
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
	int size;			// Keeps track of size for the list
	Node* head;			// Points to the first Node in the list
	Node* tail;			// Points to the last Node in the list
	Node* itr;			// Points to the 'current' Node in the list

public:
	LinkedList();			// Default Constructor

	void add(Node);			// Adds Node to the end
	void add(Node, int);	// Adds Node to a specific index
	void remove(int);		// Removes Node at a specific index

	Node get(int);			// Get the Node at a specific index

	void display();			// Prints list in the console
};

#endif

