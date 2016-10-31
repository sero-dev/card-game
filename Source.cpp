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
	LinkedList ls;

	ls.add(3);
	ls.add(2);
	ls.add(1);

	ls.remove();

	ls.display();

	return 0;
}