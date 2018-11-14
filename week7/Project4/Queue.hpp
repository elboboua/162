/********************************************************************* 
** Description: The specification file for the Queue class
*********************************************************************/ 

#ifndef QUEUE_H
#define QUEUE_H

#include "Character.hpp"

class Queue {

private:
	// the struct responsible for creating the nodes of the circular linked list
	struct QueueNode {
	
		QueueNode * next;
		QueueNode * prev;
		Character * character;
		QueueNode(Character * character1 = nullptr,  QueueNode *next1 = nullptr, QueueNode * prev1 = nullptr) {
			character = character1;
			next = next1;
			prev = prev1;
		}
	};	

	// the head of the circular linked list
	QueueNode * head;

public:
	Queue();
	~Queue();
	// returns true if there are no nodes in the queue
	bool isEmpty();
	// enqueues an element to the queue
	void addBack(Character*);
	// returns the element at the front of the queue
	Character * getFront();
	// dequeues the first element of the queue
	Character * removeFront();
	// shifts the head forward one item
	void shift();
	// prints the queue
	void printQueue();

};


#endif // QUEUE_H

