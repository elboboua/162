/**********************************************************************
 *** Author: Ahmad El-Bobou
 *** Date: 09-30-2018 
 *** Description: Project 1 - Langton's Ant 
 **********************************************************************/

#include "ant.hpp"
#include "menu.hpp"
#include <ctime>
#include <cstdlib>

// This program creates a simulation of a Langston's Ant. 
// The program takes user specified information and prints each step of the ant on the board.
int main () {
    // random seed for random ant starting point generation
    srand(time(NULL));

    bool quit;
    
    // Menu to ask if player wants to play or not
    
    quit = startMenu();

    // This while loop runs the simulation so long as the user has not quit. 
    while (!quit) {

        int rows,columns,iterations,startX,startY;
       
        
        // Menu to ask for rows, columns, iterations, starting xposition, and starting yposition.
        getInfoMenu(rows,columns,iterations,startX,startY);        


        // create a Dynamically Allocated 2darray
        string ** board = new string * [rows];
        for (int i = 0; i < rows; i++) {
            board[i] = new string [columns];
        }
        // create ant object
        Ant ant(rows,columns,iterations,startX,startY,board);

        // creates the board then runs the simulation
        ant.createBoard(board);
        ant.runSimulation(board);

        // delete dynamically allocated memory and set pointer to nullptr to avoid memory leaks
        for (int i = 0; i < rows; i++) {
            delete [] board[i];
        }

        delete [] board;
        

        // Menu to see if user wants to rerun the program
        quit = replayMenu();

    }

    return 0;

}

