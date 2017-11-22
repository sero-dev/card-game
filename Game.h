/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Game.h
 * Purpose: Implements the casino game, Blackjack with a point system, for every win,
 *			a player will 3 points, a tie will recieve 1 point and losing with reward 
 *			no points
 *
 * @author Sean Rodriguez <sean.rodriguez@outlook.com>
 * @copyright Sean Rodriguez December 28, 2016
 * @version 1.0
 */

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"

class Game {
private:
	Player** players;	// Array of players
	Player dealer;		// Dealer
	int numOfPlayers;	// Number of players 
	Deck deck;			// Deck of cards

	void convertBlackjackValues();	// Converts all cards to blackjack card values

	void beginRound();		// Starts the round of blackjack
	void addNewPlayer();	// Adds a player to the game
	void removePlayer();	// Removes a player from the game

	void announceWinners();		// Announces the winners of the rounds, rewards point as well
	void collectAllCards();		// Collects all the cards from the dealer and players

public:
	Game();		// Default Constructor
	~Game();	// Destructor

	void playGame();	// Starts game
};

#endif
