/********************************************************************* 
** Description: The specification file for the Character base Class
*********************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstdlib>

// This class is the base for the other characters
class Character {

protected:
	// HP
	int strength;
	// adds to the defense roll of the player
	int armor;

public:
	// initialized with a specific strength and armor
	Character(int strength, int armor);

	// necessary getters and setters
	int getStrength();
	int getArmor();
	void setStrength(int strength);

	// gets the rolls of both attack and defense
	virtual int attack();
	virtual int defense();

	// allows damage to be assigned to the character.
	virtual void takeDamage(int damage);
};
 
#endif // CHARACTER_H
