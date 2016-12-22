/**
 * CUNY Queens College - CS211 | CardGame
 * Name: LinkedList.h
 * Purpose: Implements a data structure based on a naive LinkedList
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez December 21, 2016
 * @version 1.0
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Card.h"

class LinkedList {

	friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);

private:
	class Node {
	private:
		Card* data;
		Node* next;
	public:
		Node(Card* data) : data(data), next(NULL) {}
		void setNext(Node* next) { this->next = next; }
		void setData(Card* data) { this->data = data; }
		Node* getNext() { return next; }
		Card* getData() { return data; }
	};

	Node* head;
	Node* tail;
	int size;

	void insertAtHead(Card* data);
	void insertAtTail(Card* data);
	Card* removeAtHead();
	Card* removeAtTail();

	bool isEmpty() const;

public:
	LinkedList();

	Card* getHead();
	Card* getTail();
	Card* getAtIndex(int index);
	
	int getSize() const;
	void insertAtIndex(Card* data, int index);

	Card* removeAtIndex(int index);
	Card* remove(Card* data);
	bool contains(Card* data);
	int search(Card* data);

	const Card& operator[](int index);

};

#endif

