/********************************************************************* 
** Description: The specification file for the Harry Potter Class
*********************************************************************/ 

#include "Character.hpp"

class HarryPotter: public Character {

private: 
	bool hasBeenRevived;

public: 
	HarryPotter();

	virtual void takeDamage(int damage);
};
