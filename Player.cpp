/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Player.cpp
 * Purpose: Implements functionality for a player, including name, hand & points
 *
 * @author Sean Rodriguez <sean.rodriguez@outlook.com>
 * @copyright Sean Rodriguez December 27, 2016
 * @version 1.0
 */

#include "Player.h"
#include <iostream>

// Default Constructor
Player::Player() :
	name(""),
	points(0)
{}

// Constructor for name
Player::Player(std::string name) :
	name(name),
	points(0)
{}

// Sets player's name
void Player::setName(std::string name) { this->name = name; }

// Gets player's name
std::string Player::getName() const { return name; }

// Adds card to player's hand
void Player::addCard(Card* card) {
	hand.insertLast(card);

	if (evaluate() >= 21)
		hand.convertAcesDown();
}

// Adds points to player
void Player::addPoints(int points) {
	this->points += points;
}

// Removes card in front of hand
Card * Player::remove() {
	return hand.remove();
}

// Evaluates the player's hand value
int Player::evaluate() const {
	return hand.evaluate();
}

// Gets number of cards in hand
int Player::getNumberOfCards() const {
	return hand.getCount();
}

// Dealer's hand; does not show first card
void Player::currentHand() const {
	hand.currentHand();
}

// Shows player's entire hand
void Player::showHand() const {
	std::cout << hand;
}

// Gets total points for player
int Player::getPoints() const { return points; }

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Player& player) {
	os << player.hand;
	return os;
}
