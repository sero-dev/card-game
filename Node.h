/**
* CUNY Queens College - CS211 | CardGame
* Name: Node.h
* Purpose: Creates a node for a LinkedList
*
* @author Sean Rodriguez <sean.rodriguez@gmail.com>
* @copyright Sean Rodriguez October 24, 2016
* @version 1.0
*/

#ifndef NODE_H
#define NODE_H

class Node {
private:
	Node* previous;		// Node before 'this' Node
	Node* next;			// Node after 'this' Node
	int data;			// Data inside 'this' Node

public:
	Node(int);			// @param Data being set inside 'this' Node

	void setPrevious(Node&);	// Set the Node before 'this' Node
	void setNext(Node&);		// Set the Node after 'this' Node
	Node getPrevious();			// Get the Node before 'this' Node
	Node getNext();				// Get the Node after 'this' Node
	int getData();				// Get the data inside the Node
};

#endif