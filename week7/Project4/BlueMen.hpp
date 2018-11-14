/********************************************************************* 
** Description: The specification file for the BlueMen Class
*********************************************************************/ 

#ifndef BLUEMEN_H
#define BLUEMEN_H

#include "Character.hpp"

class BlueMen: public Character {

public:
	BlueMen();	

	virtual int attack();
	virtual int defense(int damage);
	
};

#endif // BLUEMEN_H
