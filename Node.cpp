/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Node.cpp
 * Purpose: Creates a node for a LinkedList 
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 31, 2016
 * @version 1.0
 */

#include "Node.h"

/**
 * Initializes the data variable
 *
 * @param for Card to point to
 */
Node::Node(Card* card) {
	this->card = card;
}
