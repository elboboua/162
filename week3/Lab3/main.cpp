/*********************************************************************
** Author: Ahmad El-Bobou
** Date:10-11-2018 
** Description: Lab3 - War Dice Game
*********************************************************************/



#include <iostream>
#include <ctime>
#include <cstdlib>

//#include "Die.hpp"
//#include "LoadedDie.hpp"
#include "Game.hpp"

int main () {


    Game game;
    if (!game.beginMenu()) {
        return 0;
    }
    game.getInfo();

    std::cout << "Didn't run if it works right." << std::endl;
    return 0;
}
