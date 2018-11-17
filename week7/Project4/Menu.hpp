/********************************************************************* 
** Description: The specification file for the Menu class
*********************************************************************/
#ifndef MENU_H
#define MENU_H

#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Queue.hpp"
#include "inputValidation.hpp"

class Menu {

private:
	bool quit;
	Queue* p1;
	Queue* p2;
	Queue* dead;
	int p1Kills;
	int p2Kills;
	int rounds;
	int numOfChar;

public:
	Menu();

	// allows the players to select their characters	
	void selectCharacter();

	// creates the attack for each round
	void attackDisplay();

	// display dead
	void displayDead();

	// loops what is necessary
	void loop();

	// Asks the user if they want to play
	bool play();
	bool playAgain();
	
	~Menu();
}; 


#endif // MENU_H
