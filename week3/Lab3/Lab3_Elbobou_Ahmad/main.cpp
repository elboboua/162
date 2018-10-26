/*********************************************************************
** Author: Ahmad El-Bobou
** Date:10-11-2018 
** Description: Lab3 - War Dice Game
*********************************************************************/



#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Game.hpp"

// main function for the program. 
int main () {
    // Sets the seed for our randomizer
    srand(time(NULL));

    // creates game object
    Game game;
    if (!game.beginMenu()) {
        return 0;
    }
    // displays the rolls and winner
    game.gameLoop();

    return 0;
}
