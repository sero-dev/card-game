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
#include "LinkedList.h"

using namespace std;

int main() {

	LinkedList list;

	Card* card1 = new Card(11, 2); // Jack of Club

	list.insertAtIndex(new Card(0, 0), 0);
	list.insertAtIndex(new Card(1, 0), 1);
	list.insertAtIndex(new Card(2, 0), 1);
	list.insertAtIndex(new Card(3, 0), 1);
	list.insertAtIndex(card1, 1);

	cout << list << endl;
	cout << "Size: " << list.getSize() << endl;
	cout << "Head: " << *list.getHead() << endl;
	cout << "Tail: " << *list.getTail() << endl;
	cout << "Index 2: " << *list.getAtIndex(2) << endl;
	cout << endl;

	cout << "Search for " << *card1 << endl;
	cout << "Located at: " << list.search(card1) << endl;
	list.remove(card1);
	cout << list << endl;

	return 0;
}