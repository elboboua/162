/********************************************************************* 
** Description: Class implementation file from the Penguin Class
*********************************************************************/ 

#include "Penguin.hpp"

// Penguins cost 1000 dollars
// They can have 5 baby
// They are 1 times as expensive to feed as the base cost $10
// Their payoff is 10% of the cost. 1000*.10 = 100
Penguin::Penguin(): Animal(1000, 5, 10,100) {
	}

