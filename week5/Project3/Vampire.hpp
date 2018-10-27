/********************************************************************* 
** Description: The specification file for the Vampire class
*********************************************************************/ 

#include "Character.hpp"
#include <iostream>

class Vampire: public Character {


public:
	Vampire();
	virtual int attack();
	virtual int defense(int damage);

};
