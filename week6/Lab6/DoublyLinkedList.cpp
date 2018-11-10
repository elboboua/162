/********************************************************************* 
** Description: The class implementation file for the Doubly Linked List class
*********************************************************************/ 


#include "DoublyLinkedList.hpp"
#include <iostream>
#include <fstream>

// contructor: sets both head and tail to nullptr
DLL::DLL() {

	head = nullptr;
	tail = nullptr;

}

// deallocates the memory used by the list
DLL::~DLL() {

		DoublyLinkedList * nodePtr = head;

		while (nodePtr != nullptr) {
			DoublyLinkedList * garbage = nodePtr;
			nodePtr = nodePtr->next;
			delete garbage;
		}

		
}

// adds to the front of the list
void DLL::addToHead(int value) {

	// if condition if list is empty
	// else condition if it isn't
	if (head == nullptr) {
		head = new DoublyLinkedList(value);
		tail = head;
	} 		else {

		head = new DoublyLinkedList(value, nullptr, head);
		head->next->prev = head;

	}

}

// adds to the end of the list
void DLL::addToTail(int value) {

	// if condition if list is empty
	// else condition if it isn't
	if (tail == nullptr) {
		tail = new DoublyLinkedList(value);
		head = tail;
	} else {

		tail = new DoublyLinkedList(value, tail, nullptr);
		tail->prev->next = tail;
	}



}

// deletes the first node
void DLL::deleteFirstNode() {

	// if list is empty
	// else if there is one item in the list
	// else there is more than one item in the list
	if (head==nullptr) {

		std::cout << "ERROR! No elements to delete!" << std::endl;

	} else if (head->next == nullptr) {

		delete head;
		head = nullptr;
		tail = head;

	} else {

		DoublyLinkedList * garbage = head;
		head = head->next;
		head->prev = nullptr;
		delete garbage;

	}

}


// deletes the last node
void DLL::deleteLastNode() {

	// if list is empty
	// else if there is one item in the list
	// else there is more than one item in the list
	if (tail == nullptr) {

		std::cout << "ERROR! No elements to delete!" << std::endl;

	} else if (tail->prev == nullptr) {

		delete tail;
		tail = nullptr;
		head = tail;


	}else {

		DoublyLinkedList * garbage = tail;
		tail = tail->prev;
		tail->next = nullptr;		
		delete garbage;
	}


}

// prints the list front head to tail
void DLL::traverse() {

	std::cout << "Your linked list is: ";

	if (head == nullptr) {

		std::cout << "The list is empty." << std::endl;

	} else {

		DoublyLinkedList * nodePtr = head;
		while (nodePtr !=nullptr) {
			std::cout << nodePtr->val << " ";
			nodePtr = nodePtr->next;
		}

		std::cout << std::endl;
	}
	

}

// Prints the list in reverse
void DLL::traverseReverse() {

	std::cout << "Your reversed linked list is: ";

	if (tail== nullptr) {

		std::cout << "The list is empty." << std::endl;

	} else {

		DoublyLinkedList * nodePtr = tail;
		while (nodePtr !=nullptr) {
			std::cout << nodePtr->val << " ";
			nodePtr = nodePtr->prev;
		}

		std::cout << std::endl;
	}
	

}

// Prints the value at the head
void DLL::printHead() {
	
	if (head == nullptr) {

		std::cout << "The list is empty." << std::endl;

	} else {

		std::cout << "The value of the Head node is " << head->val << std::endl;	
	}
}

// Prints the value at the tail
void DLL::printTail() {
	if (tail == nullptr) {

		std::cout << "The list is empty." << std::endl;

	} else {

	std::cout << "The value of the Tail node is " << tail->val << std::endl;	
	}
}



// This functions populates the linked list with a list of integers from a text file. 
void DLL::createListFromFile() {

	std::ifstream ifs("numfile.txt");
	int num;

	while (ifs >> num) {

		addToTail(num);	


	}

	ifs.close();

}
