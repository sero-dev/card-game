/**
 * CUNY Queens College - CS211 | CardGame
 * Name: LinkedList.h
 * Purpose: Implements a data structure based on a naive LinkedList
 *
 * @author Sean Rodriguez <sean.rodriguez@outlook.com>
 * @copyright Sean Rodriguez December 21, 2016
 * @version 1.0
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Card.h"

class LinkedList {

	// Overloaded << operator
	friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);

private:
	// Embedded Node class
	class Node {
	private:
		Card* data;	// node data
		Node* next;	// next node 
	public:
		Node(Card* data) : data(data), next(NULL) {}		// Constructor for data
		void setNext(Node* next) { this->next = next; }		// Sets next node
		void setData(Card* data) { this->data = data; }		// Sets data inside node
		Node* getNext() { return next; }					// Gets next node
		Card* getData() { return data; }					// Gets data from node
	};

	Node* head;		// Points to the front of the list
	Node* tail;		// Points to the back of the list
	int size;		// Size of the LinkedList

	void insertAtHead(Card* data);	// Inserts data in front of the list
	void insertAtTail(Card* data);	// Inserts data in back of the list
	Card* removeAtHead();			// Removes data from the front of the list
	Card* removeAtTail();			// Removes data from the back of the list

public:
	LinkedList();					// Default Constructor

	Card* getHead();				// Returns head of the list
	Card* getTail();				// Returns tail of the list
	Card* getAtIndex(int index);	// Retruns data from specified index
	
	int getSize() const;							// Gets size of the LinkedList
	void insertAtIndex(Card* data, int index);		// Inserts data at a specified index

	Card* removeAtIndex(int index);		// Remove data at a specified index
	Card* remove(Card* data);			// Removes exact data
	bool contains(Card* data);			// Returns true if Card is in the LinkedList
	int search(Card* data);				// Gets index of the Card, returns -1 if not found

	Card* operator[](int index);		// Overloaded [] operator
	bool isEmpty() const;				// Checks if the list is empty

};

#endif

