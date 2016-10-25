/**
 * CUNY Queens College - CS211 | CardGame
 * Name: LinkedList.cpp
 * Purpose: Creates dynamic data structure that is Node-Base
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 24, 2016
 * @version 1.0
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

// Default Constructor
LinkedList::LinkedList() {
	size = 0;
}

/**
 * Adds a Node to the front of the list
 * 
 * @param Node that is being added to the list
 */
void LinkedList::add(Node n) {
	n.next = *head;
	head = &n;
	
	size++;
}

/**
 * Adds a Node to a specific index of the list
 *
 * @param Node that is being added to the list
 * @param Index at which the Node is being added at
 */
void LinkedList::add(Node n, int index) {
	if (index == 0) {
		n.next = *head;
		head = &n; 			
	} else {
		itr = get(index - 1);
		n.next = itr->next;
		itr->next = &n;
	}
	
	size++;	
	
	// OLD CODE
	/*if (index == 0) {
		n.setNext(*head);
		head->setPrevious(n);
		head = &n;
	}

	else if (index == size) {
		n.setPrevious(*tail);
		tail->setNext(n);
		tail = &n;
	}

	else {
		itr = head;
		for (int i = 1; i <= index; i++)
			itr = &(itr->getNext());

		
	}*/

	//itr = &get(index);
	//itr->getPrevious().setNext(n);
	//cout << itr->getPrevious().getNext().getData() << endl;

	//n.setPrevious(itr->getPrevious());
	//n.setNext(*itr);
	//itr->setPrevious(n);
}

/**
 * Removes the Node from  a specific index
 * 
 * @param Index where Node is to be removed from
 */
void LinkedList::remove(int index) {
	itr = get(index - 1);
	itr->next = itr->next->next;
	
	size--;
}


/**
 * Gets the Node at a specific index
 *
 * @param Index at which, to get the Node from
 * @return Node that is at the index parameter
 */
Node LinkedList::get(int index) {
	itr = head;
	for (int i = 1; i <= index; i++)
		itr = itr->next;

	return *itr;
}


// Displays all the Node data on one line in the console
void LinkedList::display() {
	for (int i = 0; i < size; i++) {
		cout << get(i).getData() << " ";
	}

	cout << endl;
}

