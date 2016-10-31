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

class Node {
	
	friend class LinkedList;	// Allows use of Node private variables for LinkedList class

private:
	int data;		// Data inside Node
	Node* next;		// Pointer to next Node

public:
	Node(int);		// Initializes data object
};

#endif
