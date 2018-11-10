/********************************************************************* 
** Description: The implementation file for the Character base Class
*********************************************************************/ 

#include "Character.hpp"
#include <iostream>
// Constructor
Character::Character(int strength, int armor, std::string type) {

	this->strength = strength;
	this->armor = armor;
	this->type = type;
	this->lastHit = 0;
}


// getters and setter
int Character::getStrength() {
	return this->strength;
}

int Character::getArmor() {
	return this->armor;
}

std::string Character::getType() {
	return this->type;
}

int Character::getLastHit () {

	// gets and resets last hit
	int temp = lastHit;
	lastHit = 0;
	return temp;

}

void Character::setStrength(int strength) {
	this->strength = strength;
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
