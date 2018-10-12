/*********************************************************************
** Author: Ahmad El-Bobou
** Date:10-11-2018 
** Description: Lab3 - War Dice Game
*********************************************************************/



#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Die.hpp"
#include "LoadedDie.hpp"

int main () {

    const int ROLLS = 20;

    // The call to srand should only be called once in the program. 
    srand(time(NULL));

    Die test(6);
    
    LoadedDie test2(6);

    int sumD, sumL;

    for (int i = 0; i < ROLLS; i++) {
        int D = test.roll();
        int L = test2.roll();    

        std::cout << "Regular: " << D << " ";
        std::cout << "Loaded: " << L <<  std::endl;
    

        sumD +=D;
        sumL +=L;
    }


    std::cout << "Regular average: " << sumD/ROLLS << std::endl;
    
    std::cout << "Loaded average: " << sumL/ROLLS << std::endl;

    return 0;
}
