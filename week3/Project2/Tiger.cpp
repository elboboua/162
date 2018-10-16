/********************************************************************* 
** Description: Class implementation file from the Tiger Class
*********************************************************************/ 

#include "Tiger.hpp"

// Tigers cost 10,000 dollars
// They can have 1 baby
// They are 5 times as expensive to feed
// Their payoff is 20% of the cost. 10,000*.20 = 2000
Tiger::Tiger(): Animal(10000, 1, 50,2000) {
	}

