/********************************************************************* 
** Description: Specification file for menu functions
*********************************************************************/

#ifndef MENU_H
#define MENU_H
// asks the user if they'd like to play
bool startMenu();

// asks the user if they'd like to play again
bool replayMenu();

// asks the user for necessary information for the simulation
void getInfoMenu(int&,int&,int&,int&,int&);

// asks the user if they want to input random start positions for the ant or not
bool isRandom();

#endif // MENU_H 
