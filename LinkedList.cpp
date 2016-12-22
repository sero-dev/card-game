/**
 * CUNY Queens College - CS211 | CardGame
 * Name: LinkedList.cpp
 * Purpose: Implements a data structure based on a naive LinkedList
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez December 21, 2016
 * @version 1.0
 *
 */

#include "LinkedList.h"

LinkedList::LinkedList() :
	head(NULL),
	tail(head),
	size(0)
{}

Card* LinkedList::getHead() {
	return head->getData();
}

Card* LinkedList::getTail() {
	return tail->getData();
}

Card* LinkedList::getAtIndex(int index) {
	if (index >= size) return tail->getData();

	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->getNext();
	}

	return current->getData();
}

int LinkedList::getSize() const { return size; }

void LinkedList::insertAtIndex(Card* card, int index) {
	Node* inserted = new Node(card);
	
	if (isEmpty()) {
		head = inserted;
		tail = inserted;
	}
	else if (index == 0) insertAtHead(card);
	else if (index > size - 1) insertAtTail(card);
	else {
		Node* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->getNext();
		}

		inserted->setNext(current->getNext());
		current->setNext(inserted);
	}

	size++;
}

Card* LinkedList::removeAtIndex(int index) {
	Card* removed;

	if (isEmpty() || index < 0 || index > size - 1) return NULL;
	else if (index == 0) removed = removeAtHead();
	else if (index == size - 1) removed = removeAtTail();
	else {
		Node* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->getNext();
		}

		removed = current->getNext()->getData();
		current->setNext(current->getNext()->getNext());
	}

	size--;
	return removed;
}

Card* LinkedList::remove(Card* card) {
	return removeAtIndex(search(card));
}

bool LinkedList::contains(Card* card) {
	return (search(card) >= 0);
}

int LinkedList::search(Card* data) {
	int index = 0;
	Node* current = head;

	while (current->getNext() != NULL) {
		if (current->getData() == data) {
			return index;
		}
		current = current->getNext();
		index++;
	}

	return -1;
}

void LinkedList::insertAtHead(Card* data) {
	Node* temp = new Node(data);
	if(head != NULL) temp->setNext(head);
	head = temp;
}

void LinkedList::insertAtTail(Card* data) {
	Node* inserted = new Node(data);
	if (tail != NULL) tail->setNext(inserted);
	tail = inserted;
}

Card* LinkedList::removeAtHead() {
	if (isEmpty()) return NULL;

	Node* removed = head;
	head = head->getNext();

	return removed->getData();
}

Card* LinkedList::removeAtTail() {
	if (isEmpty()) return NULL;

	Node* current = head;
	for (int i = 0; i < size - 2; i++) {
		current = current->getNext();
	}

	Node* removed = tail;
	current->setNext(NULL);
	tail = current;

	return removed->getData();
}

bool LinkedList::isEmpty() const {
	return (size == 0);
}

const Card& LinkedList::operator[](int index) {
	Node* current = head;
		 
	for (int i = 0; i < index; i++) {
		current = current->getNext();
	}

	return *current->getData();
}

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
	LinkedList::Node* current = list.head;

	for (int i = 0; i < list.size; i++) {
		os << *current->getData() << std::endl;
		current = current->getNext();
	}

	return os;
}
