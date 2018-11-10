/********************************************************************* 
** Description: Functions to use on linked lists
*********************************************************************/

// struct that is used as a linked list

struct LinkedList {

	double value;
	LinkedList * next; 
	
	// constructor
	LinkedList(double value1, LinkedList *next1 = nullptr) {
		value = value1;
		next = next1;		
	}



};

// Building a list by adding elements to the beginning;

int main () {


	LinkedList * linkedList = nullptr;
	double number =2;
	linkedList = new LinkedList(number, linkedList);


	delete linkedList;

	return 0;

}

