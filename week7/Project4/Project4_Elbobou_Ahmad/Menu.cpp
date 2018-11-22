/********************************************************************* 
** Description: The implementation file for the Menu class
*********************************************************************/ 

#include "Menu.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

Menu::Menu () {
	
	quit = false;
	p1 = new Queue;
	p2 = new Queue;
	dead = new Queue;
	rounds = 1;
	srand(time(NULL));
	numOfChar = 0;
	p1Kills = p2Kills = 0;

}


// allows the players to select their character types
void Menu::selectCharacter() {
	

	int input;
	
	std::cout << "Please enter the number of your desired characters: " << std::endl;
	numOfChar = isIntAboveX(0);



	// iterates depending on the selected size of the character queues
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
				p1->addBack(new Vampire);

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
void Menu::attackDisplay() {

	// iterates until one of the character queues is empty
	while (!p1->isEmpty() && !p2->isEmpty()) {

		// show who is fighting who
		std::cout << "Round " << rounds << ": ";
		rounds++;
		std::cout << "Player 1's " << p1->getFront()->getName() << " vs Player 2's " << p2->getFront()->getName() << std::endl;
	

		while (p1->getFront()->getStrength() > 0 && p2->getFront()->getStrength() > 0) {

			int damage;
			// Player 1 attacks

			damage = p1->getFront()->attack();
			p2->getFront()->defense(damage);

			// Player 2 attacks
			damage = p2->getFront()->attack();
			p1->getFront()->defense(damage);	

		}


		// Checking the victor of the game
		if (p1->getFront()->getStrength() <= 0 && p2->getFront()->getStrength() > 0) {
			std::cout << "Player 2's " << p2->getFront()->getName() <<  " wins!" << std::endl;
			dead->addBack(p1->removeFront());
			p2->getFront()->restore();
			p2->addBack(p2->removeFront());
			p2Kills++;
		} else if (p2->getFront()->getStrength() <= 0 && p1->getFront()->getStrength() > 0) {
			std::cout << "Player 1's " << p1->getFront()->getName() << " wins!" << std::endl;
			dead->addBack(p2->removeFront());
			p1->getFront()->restore();
			p1->addBack(p1->removeFront());
			p1Kills++;
		} else {
			std::cout << "DRAW! Both characters died!" << std::endl;
			dead->addBack(p2->removeFront());
			dead->addBack(p1->removeFront());
		}	

		std::cout << std::endl;
	}

	if (p1Kills == p2Kills) {
	

		std::cout << "The tournament has ended in a tie." << std::endl;
		std::cout << "Player 1 score: " << p1Kills << std::endl;
		std::cout << "Player 2 score: " << p2Kills << std::endl;

	
	} else if (p1Kills > p2Kills) {


		std::cout << "Player 1 has won the tournament!" << std::endl;
		std::cout << "Player 1 score: " << p1Kills << std::endl;
		std::cout << "Player 2 score: " << p2Kills << std::endl;

	} else if (p2Kills > p1Kills) {

		std::cout << "Player 2 has won the tournament!" << std::endl;
		std::cout << "Player 1 score: " << p1Kills << std::endl;
		std::cout << "Player 2 score: " << p2Kills << std::endl;
	}

	std::cout << "=============================================================" << std::endl;
	std::cout << std::endl;

	std::cout << "Would you like to see a list of the dead characters?" << std::endl;
	std::cout << "Enter 1 for yes, and 0 for no:" << std::endl;
	int input = isIntBetweenXAndY(0,1);

	if (input == 1) {
		displayDead();
	std::cout << "=============================================================" << std::endl;
	} 

	std::cout << std::endl;
	
}

// loops the game depending on the turns
void Menu::loop() {

	if (play()) {	

		do {		

			selectCharacter();

			
			attackDisplay();

			} while (playAgain());

	}
}


// display dead characters
void Menu::displayDead() {
	std::vector<Character *> charVec;
	while (!dead->isEmpty()) {
		charVec.push_back(dead->removeFront());
	}

	std::cout << "The dead characters are the following from last dead to first dead: " << std::endl;

	for (int i = charVec.size(); i > 0; i--) {
	
		std::cout << charVec[i-1]->getName() << " ";
	}

		std::cout << std::endl;
}



// asks user if they want to play
bool Menu::play() {

	int input;

	std::cout << "Would you like to play BATTLE TOURNAMENT?" << std::endl;
	std::cout << "Enter 1 for yes and 0 for no:" << std::endl;

	input = isIntBetweenXAndY(0,1);

	if (input ==1) {
		return true;
	} else {
		return false;
	}


}


// asks user if they want to play again
bool Menu::playAgain() {

	int input;

	std::cout << "Would you like to play again? 1 for yes, 0 for no." << std::endl;
	input = isIntBetweenXAndY(0,1);	

	std::cout << "=============================================================" << std::endl;
	if (input == 1) {
		
		rounds = 0;

		delete p1;
		p1 = nullptr;
		p1 = new Queue;
		p1Kills = 0;		

		delete p2;
		p2 = nullptr;
		p2 = new Queue;
		p2Kills = 0;

		delete dead;
		dead = nullptr;
		dead = new Queue;

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

	delete dead;
	dead = nullptr;

}
