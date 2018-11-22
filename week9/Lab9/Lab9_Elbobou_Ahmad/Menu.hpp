/********************************************************************* 
** Description: The specification file for the Menu class
*********************************************************************/ 

#pragma once

#include <queue>
#include <stack>

class Menu {


public:
	Menu();
	~Menu();
	
	// simulates a buffer
	void bufferSim();
	// displays the queue
	void displayBuffer(std::queue<int>);

	// creates a palindrome from a string
	void palindrome();


	// responsible for looping the menu
	void loop();	

};
