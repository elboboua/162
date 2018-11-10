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
#include "inputValidation.hpp"

class Menu {

private:
	bool quit;
	Character* p1;
	Character* p2;
	int rounds;

public:
	Menu();

	// allows the players to select their characters	
	void selectCharacter();

	// creates the attack for each round
	void attackDisplay();

	// loops what is necessary
	void loop();

	//
	bool playAgain();
	
	~Menu();
}; 


#endif // MENU_H
