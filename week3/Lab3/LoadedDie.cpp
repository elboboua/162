/********************************************************************* 
** Description: The specification file for the Loaded Die Class
*********************************************************************/ 

#include "LoadedDie.hpp"
#include <cstdlib>

LoadedDie::LoadedDie (int sides) : Die(sides) {     


};


// This function overrides the function from the Die class 
// This causes the roll to be on average higher. 
int LoadedDie::roll () {

    int loaded;
    int weight;

    loaded = 1+(rand()%sides);
    
    weight = rand()%3;
    
    // With this, there is a 2/3 chance that the roll with be incraesed by 3. 
    if (weight > 0) {
        loaded+=3;
    }
        
    // If the roll exceeds the number of sides, it is set to the sides variable
    if (loaded > sides) {
        loaded = sides;
    }

    return loaded;
    


}
