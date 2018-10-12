/********************************************************************* 
** Description: The implementation file for the Die class.
*********************************************************************/ 

#include <cstdlib>
#include "Die.hpp"


Die::Die(int sides) {

    this->sides = sides;


}


// simulates a roll and returns a random int from 1 - #ofSides
int Die::roll() {

    return 1+(rand()%sides);


}
