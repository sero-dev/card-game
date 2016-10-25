/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Source.cpp
 * Purpose: Driver for Card, Deck & Stack classes
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 21, 2016
 * @version 1.0 
 */

#include <iostream>
#include "Deck.h"
#include "LinkedList.h"

using namespace std;

int main() {
	Node a(9);
	Node b(8);
	Node c(7);
	Node d(6);
	Node e(5);

	LinkedList ls;

	ls.add(a);
	ls.add(b);
	ls.add(d);
	ls.add(e);

	ls.display();

	return 0;
}