/********************************************************************* 
** Description: The specification file for the Loaded Die Class
*********************************************************************/
#ifndef LOADEDDIE_H
#define LOADEDDIE_H

#include "Die.hpp"

// The loadedDie inherits the Die class.
class LoadedDie: public Die {

public: 
    LoadedDie(int);
    
    // overriding the roll function from the Die class.
    int roll();


}; 


#endif // LOADEDDIE_H
