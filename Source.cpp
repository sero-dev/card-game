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
	Deck deck;
	LinkedList hand1;
	LinkedList hand2;

	deck.shuffle();

	hand1.add(deck.deal());
	hand2.add(deck.deal());
	hand1.add(deck.deal());
	hand2.add(deck.deal());

	cout << "Player 1 Hand" << endl;
	hand1.display();

	cout << "Player 2 Hand" << endl;
	hand2.display();

	cout << "Player ";
	if (hand1 > hand2) cout << "1 Wins!";
	else cout << "2 Wins!";
	cout << endl;

	return 0;
}