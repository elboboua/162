/********************************************************************* 
** Description: The specification file for the Queue class
*********************************************************************/ 

#ifndef QUEUE_H
#define QUEUE_H

class Queue {

private:
	// the struct responsible for creating the nodes of the circular linked list
	struct QueueNode {
	
		QueueNode * next;
		QueueNode * prev;
		int value;
		QueueNode(int value1, QueueNode *next1 = nullptr, QueueNode * prev1 = nullptr) {
			value = value1;
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
	void addBack(int);
	// returns the element at the front of the queue
	int getFront();
	// dequeues the first element of the queue
	void removeFront();
	// prints the queue
	void printQueue();

};


#endif // QUEUE_H

