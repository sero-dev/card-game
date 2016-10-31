/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Node.h
 * Purpose: Creates a node for a LinkedList
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 31, 2016
 * @version 1.0
 */

#ifndef NODE_H
#define NODE_H

#include "Card.h"

class Node {
	
	friend class LinkedList;	// Allows use of Node private variables for LinkedList class

private:
	Card* card;		// Data inside Node
	Node* next;		// Pointer to next Node

public:
	Node(Card*);	// Initializes data object
};

#endif
