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
#include "Player.h"

using namespace std;

int main() {
	Deck deck;
	Player player1("Sean", 500.00);
	Player player2("Juhi", 1000.00);

	deck.shuffle();

	player1.hit(deck.deal());
	player1.hit(deck.deal());
	player2.hit(deck.deal());
	player2.hit(deck.deal());

	cout << "Player 1 Hand" << endl;
	player1.displayHand();

	cout << "Player 2 Hand" << endl;
	player2.displayHand();

	cout << "Player ";
	if (player1 > player2) cout << "1 Wins!";
	else cout << "2 Wins!";
	cout << endl;

	return 0;
}