/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Player.cpp
 * Purpose: Models the attributes of a player in a card game
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 31, 2016
 * @version 1.0
 */

#include "Player.h"

/**
 * Initializes name and cash
 *
 * @param name for player's name
 * @param cash to initialize player's cash
 */
Player::Player(std::string name, double cash) {
	this->name = name;
	this->cash = cash;
}

/**
 * Returns the player's name/cash
 *
 * @return the player's name/cash
 */
std::string Player::getName() { return name; }
double Player::getCash() { return cash; }

/**
 * Puts one card in player's hand
 * 
 * @param card that is being placed into the player's hand
 */
void Player::hit(Card* card) { 
	hand.add(card); 
}

/**
 * Removes one specified card from player's hand
 *
 * @param index of where the card is stored in the list
 * @return card that was removed
 */
Card* Player::removeCard(int index) { 
	return hand.remove(index); 
}

/**
 * Displays the player's hand
 */
void Player::displayHand() { hand.display(); }

/**
 * Operator Overloading
 * Compares the total value of the players' hands
 */
bool Player::operator>(const Player& rhs) const { return hand > rhs.hand; }
bool Player::operator<(const Player& rhs) const { return hand < rhs.hand; }
bool Player::operator==(const Player& rhs) const { return hand == rhs.hand; }
bool Player::operator!=(const Player& rhs) const { return hand != rhs.hand; }