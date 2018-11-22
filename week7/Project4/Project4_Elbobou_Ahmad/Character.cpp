/********************************************************************* 
** Description: The implementation file for the Character base Class
*********************************************************************/ 

#include "Character.hpp"
#include <iostream>
// Constructor with parameters
Character::Character(int strength, int armor, std::string type) {

	this->strength = strength;
	this->maxStrength = strength;
	this->armor = armor;
	this->type = type;
	this->name = "";
	this->lastHit = 0;

	// gets the name form the user	
	setName();
}

// default constructor
Character::Character() {

	strength = maxStrength = 0;
	armor = 0;
	type = "";
	lastHit = 0;
	name = "";
	
}

// getters and setter
int Character::getStrength() {
	return this->strength;
}

int Character::getArmor() {
	return this->armor;
}

int Character::getLastHit () {

	// gets and resets last hit
	int temp = lastHit;
	lastHit = 0;
	return temp;

}

std::string Character::getType() {
	return this->type;
}

std::string Character::getName() {
	return this->name;
}


void Character::setStrength(int strength) {
	this->strength = strength;
}

void Character::setName() {
	std::string n;
	std::cin.ignore();
	std::cout << "Please enter a name for this character: ";
	getline(std::cin, n);
	this->name = n;

}

// gets the rolls for the attack
int Character::attack() {
	int roll1,roll2;

	roll1 = 1+rand()%6;
	roll2 = 1+rand()%6;

	return roll1+roll2;

}


// gets the rolls for defense, inflicts the damage, and returns the defense roll 
int Character::defense(int attack) {
	int roll1,roll2;
	int total, totalDamage;

	roll1 = 1+rand()%6;
	roll2 = 1+rand()%6;
	total = roll1 + roll2;
	
	totalDamage = attack - total - armor;
	if (totalDamage < 0) {
		totalDamage =0;
	}	
	

	takeDamage(totalDamage);


	return total;
}



// The function used to assign damage to the character
void Character::takeDamage(int damage) {
	this->strength-= damage;
	lastHit = damage;
}

// Restores a portion of health if the character wins their match
void Character::restore() {

	if (strength < maxStrength) {
		// recovers the character a portion of his health but not above their maxStrength
		int recovery = 1 + rand()%maxStrength;
		strength += recovery;

		if (strength > maxStrength) {

			strength = maxStrength;

		}

	}	
}
