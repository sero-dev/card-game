/**
* CUNY Queens College - CS211 | CardGame
* Name: Node.cpp
* Purpose: Creates a node for a LinkedList
*
* @author Sean Rodriguez <sean.rodriguez@gmail.com>
* @copyright Sean Rodriguez October 24, 2016
* @version 1.0
*/

#include "Node.h"

/**
 * Sets data for Node
 *
 * @param Data being set to this node
 */
Node::Node(int data) {
	this->data = data;
}

/**
 * Sets connecting nodes
 *
 * @param Node that is being connected to 'this' Node
 */
void Node::setNext(Node& n) { next = &n; }
// void Node::setPrevious(Node& n) { previous = &n; }

/**
 * Gets connecting nodes
 *
 * @return Node that is connected to 'this' Node
 */
Node Node::getNext() { return *next; }
// Node Node::getPrevious() { return *previous; }

/**
 * Returns the data inside the node
 *
 * @return the data inside the node
 */
int Node::getData() { return data; }
