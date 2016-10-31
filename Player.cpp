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

Player::Player(std::string name, double cash) {
	this->name = name;
	this->cash = cash;
}

std::string Player::getName() { return name; }
double Player::getCash() { return cash; }

void Player::hit(Card* card) { hand.add(card); }
Card* Player::removeCard(int index) { return hand.remove(index); }

void Player::displayHand() { hand.display(); }

bool Player::operator>(const Player& rhs) const { return hand > rhs.hand; }
bool Player::operator<(const Player& rhs) const { return hand < rhs.hand; }
bool Player::operator==(const Player& rhs) const { return hand == rhs.hand; }
bool Player::operator!=(const Player& rhs) const { return hand != rhs.hand; }