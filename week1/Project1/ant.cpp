/********************************************************************* 
** Description: The implementation file of the Langton ant class
*********************************************************************/ 


#include "ant.hpp"
#include <cstdlib>

Ant::Ant (int r, int c, int i, int x, int y, string ** board) {

    rows = r;
    columns = c;
    iterations = i;
    xloc = x - 1;
    yloc = y -1;


    // default position is up
    direction = 0;
}


// This functions creates a blank board to start or reset the simulation
void Ant::createBoard(string **board) {

   for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = " ";
        }
    }
}

// This functions prints the board to the user
void Ant::printBoard(string ** board) {
     
   for (int i = 0; i < rows; i++) {
        
        // puts the top border
        if (i == 0) {
            for (int k = 0; k < (columns+2); k++) {
                cout << "-";
            }
            
            cout << endl;
        }
        
        // left border
        cout << "|";
        
        // goes through the elements and makes the board 
        for (int j = 0; j < columns; j++) {
            cout << board[i][j];
        }

        // right border
        cout << "|" << endl;
        
        // puts the bottom border
        if (i == (rows-1)) {
            for (int l = 0; l < (columns+2); l++) {
                cout << "-";
            } 
            cout << endl;
        }
    }
}


// This runs the simulation as many iterations as the users would like
void Ant::runSimulation(string ** board) {
    bool isWhite; 
    string antTile; 
    // place the ant on the board
    board[yloc][xloc] = "*";
    printBoard(board); 
    isWhite = true; 

    for (int i = 0; i < iterations; i++) {
    

        // if statement to adjust color of tile ant was on and change direction.
        if (isWhite) {
            board[yloc][xloc] = "#";
            direction++;
            if (direction > 3) {
                direction = 0;
            }
        } else {
            board[yloc][xloc] = " ";
            direction--;
            if (direction < 0) {
                direction = 3;
            }
        }

        // switch statement to move the ant according to new direction
        switch (direction) {

            case up:
                yloc -= 1;
                if (yloc < 0) { 
                    yloc = (rows-1);
                }
                break;

    
            case down:
                yloc += 1;
                if (yloc > (rows-1)) { 
                    yloc = 0;
                }
                break;


            case right:
                xloc += 1;
                if (xloc > (columns-1)) { 
                    xloc = 0;
                }
                break;


            case left:
                xloc -= 1;
                if (xloc < 0) { 
                    xloc = (columns-1);
                }
                break;

            default:
                cout << "There has been a problem." << endl;
        }    

        // save tile color, mark asterisk, printboard
         
        if ( board[yloc][xloc] == " ") {
        
            isWhite = true;            
 
        } else if (board[yloc][xloc] == "#") {
        
            isWhite = false;            

        }

        
        // mark the ant's location
        board[yloc][xloc] = "*";
        printBoard(board);


    }
}
