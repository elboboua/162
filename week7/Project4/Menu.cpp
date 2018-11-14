/********************************************************************* 
** Description: The implementation file for the Menu class
*********************************************************************/ 

#include "Menu.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


Menu::Menu () {
	
	quit = false;
	p1 = new Queue;
	p2 = new Queue;
	dead = new Queue;
	rounds = 1;
	srand(time(NULL));
	numOfChar = 0;

}


// allows the players to select their character types
void Menu::selectCharacter() {
	

	int input;
	Character * tempChar;
	
	std::cout << "Please enter the number of your desired characters: " << std::endl;
	numOfChar = isIntAboveX(0);




	for (int i = 0; i < numOfChar; i++) {	


		std::cout << "=============================================================" << std::endl;
		
		// Get character info from Player 1
		std::cout << "Please enter the number of your desired character, Player 1: " << std::endl;
		std::cout << "1. Vampire" << std::endl;
		std::cout << "2. Barbarian" << std::endl;
		std::cout << "3. Blue Men" << std::endl;
		std::cout << "4. Medusa" << std::endl;
		std::cout << "5. Harry Potter" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		input= isIntBetweenXAndY(1,5);

		switch (input) {
			// Vampire
			case 1:
				std::cout << "You have chosen: Vampire" << std::endl;
				tempChar = new Vampire;
				p1->addBack(tempChar);
				std::cout << "does this show up?" << std::endl;
				break;
			// Barbarian
			case 2:	
				std::cout << "You have chosen: Barbarian" << std::endl;
				p1->addBack(new Barbarian);
				break;
			// Blue Men
			case 3:
				std::cout << "You have chosen: Blue Men" << std::endl;
				p1->addBack(new BlueMen);
				break;
			// Medusa
			case 4:
				std::cout << "You have chosen: Medusa" << std::endl;
				p1->addBack(new Medusa);
				break;
			// Harry Potter
			case 5:
				std::cout << "You have chose: Harry Potter" << std::endl;
				p1->addBack(new Medusa);
				break;
		

		}

	}

	for (int i = 0; i < numOfChar; i++) {	


		std::cout << "=============================================================" << std::endl;
		
		// Get character info from Player 1
		std::cout << "Please enter the number of your desired character, Player 2: " << std::endl;
		std::cout << "1. Vampire" << std::endl;
		std::cout << "2. Barbarian" << std::endl;
		std::cout << "3. Blue Men" << std::endl;
		std::cout << "4. Medusa" << std::endl;
		std::cout << "5. Harry Potter" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		input= isIntBetweenXAndY(1,5);

		switch (input) {
			// Vampire
			case 1:
				std::cout << "You have chosen: Vampire" << std::endl;
				p2->addBack(new Vampire);
				break;
			// Barbarian
			case 2:	
				std::cout << "You have chosen: Barbarian" << std::endl;
				p2->addBack(new Barbarian);
				break;
			// Blue Men
			case 3:
				std::cout << "You have chosen: Blue Men" << std::endl;
				p2->addBack(new BlueMen);
				break;
			// Medusa
			case 4:
				std::cout << "You have chosen: Medusa" << std::endl;
				p2->addBack(new Medusa);
				break;
			// Harry Potter
			case 5:
				std::cout << "You have chose: Harry Potter" << std::endl;
				p2->addBack(new Medusa);
				break;
		

		}

	}
	std::cout << "=============================================================" << std::endl;
}

// creates the attacks for each round
//void Menu::attackDisplay() {
//
//	int damage;
//
//	while (p1->getStrength() > 0 && p2->getStrength() > 0) {
//
//		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
//		std::cout << "ROUND " << rounds << std::endl;
//		rounds++;
//		// Player 1 attacks
//		std::cout << "=============================================================" << std::endl;
//		std::cout << std::endl;
//		std::cout << "Attacker: Player 1" << std::endl;
//		std::cout << "	Type: " << p1->getType() << std::endl;
//		std::cout << "Defender: Player 2" << std::endl;
//		std::cout << "	Type: " << p2->getType() << std::endl;
//		std::cout << "	Armor: " << p2->getArmor() << std::endl;
//		std::cout << "	Strength Points: " << p2->getStrength() << std::endl;
//
//		std::cout << "-------------------------------------------------------------" << std::endl;
//		damage = p1->attack();
//		std::cout << std::endl;
//		std::cout << "Player 1 Attack Roll: " << damage << std::endl;
//		std::cout << "Player 2 Defense Roll: " << p2->defense(damage) << std::endl;
//		std::cout << "Player 2 Actual Damage Taken: " << p2->getLastHit() << std::endl;
//		std::cout << "Player 2 Strength: " << p2->getStrength() << std::endl;
//		std::cout << std::endl;
//
//
//		std::cout << "=============================================================" << std::endl;
//		// Player 2 attacks
//		std::cout << std::endl;
//		std::cout << "Attacker: Player 2" << std::endl;
//		std::cout << "	Type: " << p2->getType() << std::endl;
//		std::cout << "Defender: Player 1" << std::endl;
//		std::cout << "	Type: " << p1->getType() << std::endl;
//		std::cout << "	Armor: " << p1->getArmor() << std::endl;
//		std::cout << "	Strength Points: " << p1->getStrength() << std::endl;
//
//		std::cout << "-------------------------------------------------------------" << std::endl;
//		damage = p2->attack();
//		std::cout << std::endl;
//		std::cout << "Player 2 Attack Roll: " << damage << std::endl;
//		std::cout << "Player 1 Defense Roll: " << p1->defense(damage) << std::endl;
//		std::cout << "Player 1 Actual Damage Taken: " << p1->getLastHit() << std::endl;
//		std::cout << "Player 1 Strength: " << p1->getStrength() << std::endl;
//		std::cout << std::endl << std::endl;
//		std::cout << "=============================================================" << std::endl;
//		std::cout << std::endl << std::endl;
//		std::cout << std::endl << std::endl;
//	}
//	
//		
//	if (p1->getStrength() <= 0 && p2->getStrength() > 0) {
//		std::cout << "Player 2 wins!" << std::endl;
//	} else if (p2->getStrength() <= 0 && p1->getStrength() > 0) {
//		std::cout << "Player 1 wins!" << std::endl;
//	} else {
//		std::cout << "DRAW! No one won!" << std::endl;
//	}	
//
//	
//}

// loops the game depending on the turns
//Void Menu::loop() {
//
//	do {		
//
//		selectCharacter();
//
//		
//		attackDisplay();
//
//		} while (playAgain());
//}


// asks user if they want to play again
bool Menu::playAgain() {

	int input;

	std::cout << "Would you like to play again? 1 for yes, 0 for no." << std::endl;
	input = isIntBetweenXAndY(0,1);	

	if (input == 1) {
		
		delete p1;
		p1 = nullptr;		

		delete p2;
		p2 = nullptr;

		return true;

	} else  {

		return false;
	}


}

// frees the memory used by the pointers
Menu::~Menu() {

	delete p1;
	p1 = nullptr;

	delete p2;
	p2 = nullptr;

}
