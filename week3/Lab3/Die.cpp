/********************************************************************* 
** Description: The implementation file for the Die class.
*********************************************************************/ 

#include <cstdlib>
#include "Die.hpp"

// The constructor definition
Die::Die(int sides) {

    this->sides = sides;


}


// simulates a roll and returns a random int from 1 - #ofSides
int Die::roll() {

    return 1+(rand()%sides);


}
