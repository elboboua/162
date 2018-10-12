/********************************************************************* 
** Description: The specification file for the Die class.
*********************************************************************/ 
#ifndef DIE_H
#define DIE_H

class Die {

protected:
    // the number of sides of the die
    int sides;


public:
    Die(int);


    // simulates a roll and returns a random int from 1 - #ofSides
    int roll();

};

#endif // DIE_H
