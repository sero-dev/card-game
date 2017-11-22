/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Game.cpp
 * Purpose: Implements the casino game, Blackjack with a point system, for every win,
 *			a player will 3 points, a tie will recieve 1 point and losing with reward
 *			no points
 *
 * @author Sean Rodriguez <sean.rodriguez@outlook.com>
 * @copyright Sean Rodriguez December 28, 2016
 * @version 1.0
 */

#include "Game.h"

// Default Constructor
Game::Game() :
	players(new Player*[6]),
	numOfPlayers(1)
{
	std::string name;

	std::cout << "Before you start... " << std::endl;
	std::cout << "Enter player 1's name: "; std::cin >> name;
	players[0] = new Player(name);
	dealer.setName("Dealer");

	system("CLS");

	convertBlackjackValues();
}

// Destructor
Game::~Game() {
	delete[] players;
}

// Converts all cards to blackjack card values
void Game::convertBlackjackValues() {
	Card* c[52];						

	for (int i = 0; i < 52; i++) {				
		c[i] = deck.deal();						
		if (c[i]->getRank() == 1)
			c[i]->setValue(11);
		else if (c[i]->getRank() == 11 || 
			c[i]->getRank() == 12 || 
			c[i]->getRank() == 13) {
			c[i]->setValue(10);
		}
	}

	for (int i = 0; i < 52; i++) {
		deck.placeBack(c[i]);
	}
}

// Starts the game
void Game::playGame() {
	int select;

	std::cout << "----- BLACKJACK! -----" << std::endl;
	std::cout << std::endl;

	std::cout << "----- Leaderboards -----" << std::endl;
	for (int i = 0; i < numOfPlayers; i++)
		std::cout << players[i]->getName() << ": " << players[i]->getPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "[1] - Start Round" << std::endl;
	std::cout << "[2] - Add new player" << std::endl;
	std::cout << "[3] - Remove player" << std::endl;
	std::cout << "[4] - Exit Game" << std::endl;
	std::cout << std::endl;

	std::cout << "Select an option: "; std::cin >> select;
	std::cout << std::endl;

	switch (select) {
	case 1:
		beginRound();
		break;
	case 2:
		addNewPlayer();
		break;
	case 3:
		removePlayer();
		break;
	case 4:
		exit(1);
	default:
		std::cout << "Invalid selection: Try Again" << std::endl;
	}

	system("CLS");
	playGame();
}

// Adds new players to the game
void Game::addNewPlayer() {
	if (numOfPlayers == 6) 
		std::cout << "Table is already full" << std::endl;
	else {
		std::string name;
		std::cout << "Enter player name: "; std::cin >> name;

		players[numOfPlayers++] = new Player(name);
	}
}

// Removes players from the game
void Game::removePlayer() {
	int index;

	std::cout << "Enter the index of the player to be removed: "; std::cin >> index;
	std::cout << std::endl;

	if (numOfPlayers == 0) 
		std::cout << "There are no players at this table" << std::endl;
	else if (index < 0 || index > numOfPlayers - 1)
		std::cout << "Index out of bounds" << std::endl;
	else {
		for (int i = index; i < numOfPlayers; i++)
			players[i] = players[i + 1];

		numOfPlayers--;
	}
}

// Starts the round of blackjack
void Game::beginRound() {
	int select;

	system("CLS");
	deck.shuffle();
	
	std::cout << "Dealing cards out..." << std::endl;
	std::cout << std::endl;

	// Deals cards to all the players
	for (int i = 0; i < numOfPlayers; i++) {
		players[i]->addCard(deck.deal());
		players[i]->addCard(deck.deal());

		std::cout << "----- " << players[i]->getName() << "'s Hand -----" << std::endl;
		players[i]->showHand();
		std::cout << std::endl;
	}

	system("PAUSE");
	system("CLS");
	////////////////////////////////////////////////////////////////////////////////////

	// For each player turn, they are prompted to hit or stand
	for (int i = 0; i < numOfPlayers; i++) {
		if (players[i]->evaluate() == 21)
			break;

		do {
			std::cout << "----- " << players[i]->getName() << "'s Turn -----" << std::endl;
			std::cout << "Hand Value: " << players[i]->evaluate() << std::endl;
			std::cout << std::endl;

			std::cout << "----- " << players[i]->getName() << "'s Hand -----" << std::endl;
			players[i]->showHand();
			std::cout << std::endl;

			std::cout << "[1] - Hit" << std::endl;
			std::cout << "[2] - Stand" << std::endl;
			std::cout << std::endl;

			std::cout << "Enter a selection: "; std::cin >> select;
			std::cout << std::endl;

			switch (select) {
			case 1:
				players[i]->addCard(deck.deal());
				break;
			case 2:
				break;
			default:
				std::cout << "Invalid selection: Try Again..." << std::endl;
			}

			if (players[i]->evaluate() > 21) {
				system("CLS");
				std::cout << "BUST!" << std::endl;
				std::cout << std::endl;

				std::cout << "Hand Value: " << players[i]->evaluate() << std::endl;
				std::cout << "----- " << players[i]->getName() << "'s Hand -----" << std::endl;
				players[i]->showHand();
				std::cout << std::endl;

				system("PAUSE");
			}

			system("CLS");

		} while (players[i]->evaluate() < 21 && select != 2);
	}
	////////////////////////////////////////////////////////////////////////////////////

	// Dealer's Turn
	std::cout << "----- Dealer's Turn -----" << std::endl;
	std::cout << std::endl;

	while (dealer.evaluate() < 17) {
		std::cout << "----- Dealer's Hand -----" << std::endl;
		std::cout << std::endl;

		dealer.addCard(deck.deal());
		dealer.addCard(deck.deal());
		
		dealer.currentHand();
		std::cout << "???? of ????" << std::endl;
		
		std::cout << std::endl;

		if (dealer.evaluate() > 21) {
			system("CLS");
			std::cout << "BUST!" << std::endl;
			std::cout << std::endl;

			std::cout << "----- Dealer's Hand -----" << std::endl;
			dealer.currentHand();
			std::cout << "???? of ????" << std::endl;
			std::cout << std::endl;
		}

		system("PAUSE");
		system("CLS");
	}
	////////////////////////////////////////////////////////////////////////////////////

	// Shows all the hands for all participates
	std::cout << "Showing all hands..." << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < numOfPlayers; i++) {
		std::cout << "----- " << players[i]->getName() << "'s Hand -----" << std::endl;
		players[i]->showHand();
		std::cout << std::endl;
	}

	std::cout << "----- Dealer's Hand -----" << std::endl;
	dealer.showHand();
	std::cout << std::endl;

	announceWinners();

	collectAllCards();
	system("PAUSE");
	system("CLS");
}

// Collects all the cards from the dealer and the players
void Game::collectAllCards() {
	for (int i = 0; i < numOfPlayers; i++)
		while(players[i]->getNumberOfCards() != 0)
			deck.placeBack(players[i]->remove());

	while(dealer.getNumberOfCards() != 0)
		deck.placeBack(dealer.remove());
}

// Announces the winners of the round, and rewards the points as well
void Game::announceWinners() {
	for (int i = 0; i < numOfPlayers; i++) {
		if ((players[i]->evaluate() > dealer.evaluate() || dealer.evaluate() > 21) && players[i]->evaluate() <= 21) {
			std::cout << players[i]->getName() << " won: +3 points" << std::endl;
			players[i]->addPoints(3);
		}
		else if (players[i]->evaluate() == dealer.evaluate() && players[i]->evaluate() <= 21) {
			std::cout << players[i]->getName() << " tied: +1 points" << std::endl;
			players[i]->addPoints(1);
		}
		else
			std::cout << players[i]->getName() << " lost: 0 points" << std::endl;
	}

	std::cout << std::endl;
}