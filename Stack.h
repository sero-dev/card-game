/**
 * CUNY Queens College - CS211 | CardGame
 * Name: Stack.h
 * Purpose: Creates a data structure that mimics the Standard Stack class
 *
 * @author Sean Rodriguez <sean.rodriguez@gmail.com>
 * @copyright Sean Rodriguez October 21, 2016
 * @version 1.0
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack {
	friend std::ostream& operator<<(std::ostream& os, const Stack& data) {
	
		for (int i = data.size - 1; i >= 0; i--)
			os << *data.stack[i] << std::endl;

		return os;
	}

private:
	int size;			// Number of items in array
	int capacity;		// Max capacity of array
	T* stack;			// Points to data array
	
	bool isFull() const;		// Checks if array is full
	bool isEmpty() const;		// Checks if array is empty

public:
	Stack(int capacity);			// Initializes all member variables
	
	~Stack();								// Destructor
	Stack(const Stack& copy);				// Copy Constructor
	Stack operator=(const Stack& copy);		// Assignment Operator

	Stack push(T data);		// Pushs data at the end
	T pop();					// Removes data at the end
	T peep() const;				// Views data at the end
};

template <class T>
Stack<T>::Stack(int capacity) : 
	size(0),
	capacity(capacity),
	stack(new T[capacity])
{}

template <class T>
Stack<T>::~Stack() {
	delete[] stack;
}

template <class T>
Stack<T>::Stack(const Stack& copy) :
	size(copy.size),
	capacity(copy.capacity),
	stack(new T[capacity])
{
	for (int i = 0; i < size; i++) {
		stack[i] = copy.stack[i];
	}
}

template <class T>
Stack<T> Stack<T>::operator=(const Stack& copy) {
	size = copy.size;
	capacity = copy.capacity;

	delete[] stack;

	stack = new T[capacity];
	for (int i = 0; i < size; i++) {
		stack[i] = copy.capacity[i];
	}

	return *this;
}

template <class T>
Stack<T> Stack<T>::push(T data) {
	if (isFull())												// Checks if stack is full...
		std::cout << "Error: Capacity full" << std::endl;		// ... displays error message
	else
		stack[size++] = data;									// Add data to stack

	return *this;												// Return this stack
}

template <class T>
T Stack<T>::pop() {
	if (isEmpty()) {											// Checks if stack is empty...
		std::cout << "Error: Stack is empty." << std::endl;		// ... displays error message... 
		exit(-1);												// ... exits program
	}

	return stack[--size];
}

template <class T>
T Stack<T>::peep() const {
	if (isEmpty()) {											// Checks if stack is empty...
		std::cout << "Error: Stack is empty." << std::endl;		// ... displays error message...
		exit(-1);												// ... exits program
	}

	return stack[size - 1];										// Returns the top index
}

template <class T>
bool Stack<T>::isFull() const { return size == capacity; }  

template <class T>
bool Stack<T>::isEmpty() const { return size == 0; }

#endif
