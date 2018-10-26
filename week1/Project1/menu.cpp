/********************************************************************* 
** Description: Implementation file for the menu functions
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
#include <ctime>

// The opening menu that asks the user if they want to run the program.
bool startMenu() {
    string answer;
    bool goodInput=false;

    while (!goodInput) {

        cout << "Would you like to run a simulation? (y or n):" << endl;
        cin >> answer;


        // tests the answer and also acts as input validation.

        if (answer == "y" || answer == "Y"){
            return false;
            goodInput = true;
        } else if (answer == "n" || answer == "N") {
            return true;
            goodInput = true;
        } else {
            cout << "ERROR!! INPUT INVALID. Please try again" << endl;
        }  
   
    }


    return false;
} 


// The menu that displays at the end of the program to see if the user wants to run it again
bool replayMenu() {
    string answer;
    bool goodInput=false;

    while (!goodInput) {

        cout << "Would you like to run a simulation again? (y or n):" << endl;
        cin >> answer;


        // tests the answer and also acts as input validation.

        if (answer == "y" || answer == "Y"){
            return false;
            goodInput = true;
        } else if (answer == "n" || answer == "N") {
            return true;
            goodInput = true;
        } else {
            cout << "ERROR!! INPUT INVALID. Please try again" << endl;
        }  
   
    }


    return false;
} 

// If the user wants to run the simulation, this menu gets the necessary information to proceed.
void getInfoMenu(int &rows, int&columns, int &iterations, int &startX, int &startY) {

    cout << "How many units wide would you like the simulation?" << endl;   
    columns = isIntAboveZero();

    cout << "How many units tall would you like the simulation?" << endl;   
    rows = isIntAboveZero();

    cout << "How many times would you like the ant to move?" << endl;
    iterations = isIntAboveZero();   
    
    // Ant starting position, random or manual
    if (isRandom()) {
        
        startY = ((rand()%(rows -1)) + 1);
        startX = ((rand()%(columns-1)) + 1);
     
    } else {

        cout << "Which # row would you like the ant to start in?" << endl;
        startY = startPosVal(columns);

        cout << "Which # column would you like the ant to start in?" << endl;
        startX = startPosVal(rows);

    } 
        


}

// Ant location menu
bool isRandom() {
    string answer;
    bool goodInput;

    do {

        goodInput = false;
        
        cout << "Would you like to assign a random start location for the ant? (y or n):" << endl;
        cin >> answer;


        // tests the answer and also acts as input validation.

        if (answer == "y" || answer == "Y" || answer == "n" || answer == "N") {
            goodInput = true;
        } else {
            cout << "ERROR!! INPUT INVALID. Please try again" << endl;
        }  
   
    } while (!goodInput);

    if (answer == "y" || answer == "Y") {
        return true;
    } else if (answer == "n" || answer == "N") {
        return false;
    }


   // in case an error occurs. 
    return false;
}





