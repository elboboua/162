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

// The constructor for the game class. 
Game::Game() {

quit = false;

p1Score = p2Score = 0;
rounds = 0;
p1IsLoaded = p2IsLoaded = false;
die = nullptr;
loadedDie = nullptr;
p1Rolls = p2Rolls = nullptr;

}

// This function asks the user if they'd like to play. 
bool Game::beginMenu() {

    
    string answer;
    bool goodInput=false;

    while (!goodInput) {

        cout << "Would you like to run a simulation? (y or n):" << endl;
        cin >> answer;


        // tests the answer and also acts as input validation.

        if (answer == "y" || answer == "Y"){
            goodInput = true;
            // If the player chooses to play, info is requested. 
            getInfo();
            return true;
        } else if (answer == "n" || answer == "N") {
            goodInput = true;
            return false;
        } else {
            cout << "ERROR!! INPUT INVALID. Please try again" << endl;
        }  

    }

    return false;
}


// This function gets all the necessary information from the users to complete the game. 
void Game::getInfo() {

    // needs int above 0 validation
    cout << "How many rounds would you like to play?" << endl;
    rounds = isIntAboveX(0); 


    // These need int validation
    cout << "Player 1: Enter 1 for a loaded die or 0 for a regular die: " << endl;
    p1IsLoaded = isIntAboveXBelowY(-1,2);
    
    cout << "Player 2: Enter 1 for a loaded die or 0 for a regular die: " << endl;
    p2IsLoaded = isIntAboveXBelowY(-1,2);

    // needs int above 4 validation
    cout << "How many sides would you like, player 1?" << endl;
    p1Sides = isIntAboveX(1);

    cout << "How many sides would you like, player 2?" << endl;
    p2Sides = isIntAboveX(1);
}

// This function creates the die objects, rolls, and stores the info to later be compared.  
void Game::getRolls() {


        
    // Creates the dice objects for p1 one and stores the rolls in an array
    if (p1IsLoaded) {
        
        loadedDie = new LoadedDie(p1Sides);
        p1Rolls = new int[rounds];        

        for (int i = 0; i < rounds; i++) {
                p1Rolls[i] = loadedDie->roll();
        }
    
        delete loadedDie;
        loadedDie = nullptr;
        
    } else {

        die = new Die(p1Sides);
        p1Rolls = new int[rounds];        

        for (int i = 0; i < rounds; i++) {
                p1Rolls[i] = die->roll();
        }  
        delete die;
        die = nullptr;
    }

    // Creates te dice objects for p2 and stores the rolls in an array
    if (p2IsLoaded) {

        loadedDie = new LoadedDie(p2Sides);
        p2Rolls = new int[rounds];        

        for (int i = 0; i < rounds; i++) {
                p2Rolls[i] = loadedDie->roll();
    }  
    
        delete loadedDie;
        loadedDie = nullptr;

    } else { 

        die = new Die(p2Sides);
        p2Rolls = new int[rounds];        

        for (int i = 0; i < rounds; i++) {
                p2Rolls[i] = die->roll();
        }  
        delete die;
        die = nullptr;


    }
    
}


// This functions takes the rolls stores in the pointer arrays and presents the to the user. 
void Game::gameLoop() {

    getRolls();

    // This section creates a string to output the die type of each player
    string p1Die, p2Die;

    if (p1IsLoaded) {
        p1Die = "loaded";
    } else {
        p1Die = "regular";
    } 

    if (p2IsLoaded) {
        p2Die = "loaded";
    } else {
        p2Die = "regular";
    }

    // This is the beginning of the print section 
    cout << endl;
    cout << "Let the game begin!" << endl;

    for (int i = 0; i < rounds; i++)   {
    
        // displays the dice rolls for each player.
        cout << "Roll #" << i+1 << "." << endl;
        cout << "Player 1 rolls a " << p1Rolls[i] << " from a " << p1Die << " die with " << p1Sides << ". " ;
        cout << "Player 2 rolls a " << p2Rolls[i] << " from a " << p2Die << " die with " << p2Sides << "." << endl;

        if (p1Rolls[i] > p2Rolls[i]) {
            p1Score++;
            cout << "1 point to Player 1!" << endl;
        } else if (p1Rolls[i] < p2Rolls[i]) {
            p2Score++;
            cout << "1 point to Player 2!" << endl;
        } else {
            cout << "DRAW!" << endl;
        }

        cout << "Player 1 score: " << p1Score << endl;
        cout << "Player 2 score: " << p2Score << endl;
        cout << endl;
    }


    if (p1Score > p2Score) {
        cout << "Final score:" << endl;
        cout << "Player 1 score: " << p1Score << endl;
        cout << "Player 2 score: " << p2Score << endl;
        cout << "Player 1 has won!" << endl;
    } else if (p2Score > p1Score) {
        cout << "Final score:" << endl;
        cout << "Player 1 score: " << p1Score << endl;
        cout << "Player 2 score: " << p2Score << endl;
        cout << "Player 2 has won!" << endl;
    } else {
        cout << "Final score:" << endl;
        cout << "Player 1 score: " << p1Score << endl;
        cout << "Player 2 score: " << p2Score << endl;
        cout << "DRAW! No one has won!" << endl;
    }   

}

// The purpose of this destructor is to free the memory from the 
// dynamically allocated arrays that held the rolls. 
Game::~Game () {


    delete p1Rolls;
    p1Rolls = nullptr;

    delete p2Rolls;
    p2Rolls = nullptr;

}
