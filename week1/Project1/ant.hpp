/********************************************************************* 
*** Description: The Langton ant class specification file
**********************************************************************/ 

#ifndef ANT_H
#define ANT_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

class Ant {

private:
    // Location of the ant
    int xloc, yloc;
    // Variables for the size of the board
    int rows, columns;
    int direction;
    // an enum definition to make direction assignment more friendly to other programmers. 
    enum orientation {up, right, down, left};
    int iterations;
public:
    Ant(int, int, int, int, int, string **);
    void createBoard(string **);
    void printBoard(string **);
    void runSimulation(string**);
};

#endif // ANT_H
