/********************************************************************* 
** Description: The implementation file for the Game class.
*********************************************************************/ 


#include "Game.hpp"
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Game::Game() {

quit = false;

p1Score = p2Score = 0;
rounds = 0;
p1IsLoaded = p2IsLoaded = false;
die = nullptr;
loadedDie = nullptr;
p1Rolls = p2Rolls = nullptr;

}


bool Game::beginMenu() {

    
    string answer;
    bool goodInput=false;

    while (!goodInput) {

        cout << "Would you like to run a simulation? (y or n):" << endl;
        cin >> answer;


        // tests the answer and also acts as input validation.

        if (answer == "y" || answer == "Y"){
            cout << "Player wants to continue." << endl;
            goodInput = true;
            return true;
        } else if (answer == "n" || answer == "N") {
            cout << "Player wants to quit." << endl;
            goodInput = true;
            return false;
        } else {
            cout << "ERROR!! INPUT INVALID. Please try again" << endl;
        }  

    }

    return false;
}


void Game::getInfo() {

    // needs int above 0 validation
    cout << "How many rounds would you like to play?" << endl;
    cin >> rounds; 


    // These need int validation
    cout << "Player 1: Enter 1 for a loaded die or 0 for a regular die: " << endl;
    cin >> p1IsLoaded;
    
    cout << "Player 2: Enter 1 for a loaded die or 0 for a regular die: " << endl;
    cin >> p2IsLoaded;

    // needs int above 4 validation
    cout << "How many sides would you like, player 1?" << endl;
    cin >> p1Sides;

    cout << "How many sides would you like, player 2?" << endl;
    cin >> p2Sides;
}

