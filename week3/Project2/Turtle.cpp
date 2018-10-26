/********************************************************************* 
** Description: Class implementation file from the Animal Class
*********************************************************************/ 

#include "Turtle.hpp"

// Turtles cost 100 dollars
// They can have 10 baby
// They are .5 times as expensive to feed that the base cost $10
// Their payoff is 5% of the cost. 100*.05 = 5
Turtle::Turtle(): Animal( 100, 10, 5, 5) {
	}

