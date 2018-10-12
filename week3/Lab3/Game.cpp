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

// This function asks the user if they'd like to play. 
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

// This function gets all the necessary information from the users to complete the game. 
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
 
void Game::getRolls() {


    getInfo();
        
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

    cout << endl;
    cout << "Let the game begin!" << endl;

    for (int i = 0; i < rounds; i++)   {
    
        // displays the dice rolls for each player.
        cout << "Roll #" << i+1 << "." << endl;
        cout << "Player 1 rolls a " << p1Rolls[i] << " from a die with " << p1Sides << ". " ;
        cout << "Player 2 rolls a " << p2Rolls[i] << " from a die with " << p2Sides << "." << endl;

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

