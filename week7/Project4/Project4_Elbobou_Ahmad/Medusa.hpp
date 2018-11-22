/********************************************************************* 
** Description: The specification file for the Medusa class
*********************************************************************/ 

#ifndef MEDUSA_H
#define MEDUSA_H

#include "Character.hpp"

class Medusa: public Character {

public:
	Medusa();
	virtual int attack();
	virtual int defense(int damage);


};

#endif // MEDUSA_H
