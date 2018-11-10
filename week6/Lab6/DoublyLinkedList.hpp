/********************************************************************* 
** Description: The class specification file for the Doubly Linked List Class
*********************************************************************/ 

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

// This class handles the making and manipulation of a doubly linked list
class DLL {


private:
	// a struct is used and a constructor is provided for easy creation of nodes
	struct DoublyLinkedList {

		int val;
		DoublyLinkedList *prev;
		DoublyLinkedList *next;
		
		DoublyLinkedList(int value, DoublyLinkedList * prev1= nullptr, DoublyLinkedList * next1 = nullptr) {
	
			val = value;
			prev = prev1;
			next = next1;

		}
		
	};

	DoublyLinkedList * head;
	DoublyLinkedList * tail;

public:
	DLL();
	~DLL();

	// These functions are used to manipulate and display the data from the list
	void addToHead(int);
	void addToTail(int);
	void deleteFirstNode();
	void deleteLastNode();
	void traverse();
	void traverseReverse();
	void printHead();
	void printTail();
	void createListFromFile();
};

#endif // DOUBLYLINKEDLIST_H

