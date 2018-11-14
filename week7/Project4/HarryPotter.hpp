/********************************************************************* 
** Description: The specification file for the Harry Potter Class
*********************************************************************/ 

#include "Character.hpp"

class HarryPotter: public Character {

private: 
	// a bool value to ensure that harry is not resurrected twice
	bool hasBeenRevived;

public: 
	HarryPotter();

	virtual void takeDamage(int damage);
};
