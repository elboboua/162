/********************************************************************* 
** Description: The implementation file for the Queue class
*********************************************************************/ 

#include "Queue.hpp"
#include <iostream>

Queue::Queue() {
	head = nullptr;
}

Queue::~Queue() {
	// This only runs if there have been any dynamic objects created
	if (!isEmpty()) {
		// turns the queue into a linked list and deletes it
		head->prev->next = nullptr;
		QueueNode * garbage;

		while (head != nullptr) {
			garbage = head;
			delete garbage->character;
			garbage->character = nullptr;
			head = head->next;
			delete garbage;
		}	
	}
}

// returns true if there are no nodes in the queue
bool Queue::isEmpty() {
	if (head == nullptr) {
		return true;
	} else {
		return false;	
	}
}

// returns the element at the front of the queue
Character * Queue::getFront() {
	return head->character;
}

// enqueues an element
void Queue::addBack(Character * ch) {
	
	if (isEmpty()) {
		head = new QueueNode(ch);
		head->next = head;
		head->prev = head;
	} else {
		head->prev = new QueueNode(ch, head, head->prev);
		head->prev->prev->next = head->prev;
	}
	
}

// dequeues the first element
// this function must be proceeded by an isEmpty() check
Character * Queue::removeFront() {
	
	// create the character to be returned
	Character * tempChar;
	tempChar = head->character;

	// if there is one element in the list
	if (head==head->next && head==head->prev) {
		delete head;
		head = nullptr;
	} else {
		// if there is more than 1 element
		// link the last element in the queue to the second element
		head->prev->next = head->next;
		// link the second element in the queue to the last element
		head->next->prev = head->prev;
		// hand over the first element to a temp var
		QueueNode * temp = head;
		head = head->next;
		// delete the var
		delete temp;

	}

	return tempChar;

}

// shifts the head forward one item
void Queue::shift() {

	head = head->next;

}

// prints the queue
void Queue::printQueue() {
	
	QueueNode * node = head;
	
	do {

		std::cout << node->character->getType() << " ";
		node = node->next;


	} while (node != head);

	std::cout << std::endl;

}
