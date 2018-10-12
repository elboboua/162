/********************************************************************* 
** Description: The specification file for the Loaded Die Class
*********************************************************************/
#ifndef LOADEDDIE_H
#define LOADEDDIE_H

#include "Die.hpp"

// The loadedDie inherits the Die class.
class LoadedDie: public Die {

public: 
    // overriding the roll function from the Die class.
    LoadedDie(int);
    int roll();


}; 


#endif // LOADEDDIE_H
