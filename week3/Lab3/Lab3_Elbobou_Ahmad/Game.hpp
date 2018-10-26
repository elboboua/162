/********************************************************************* 
** Description: The specification file for the Game class.
*********************************************************************/ 

#include "Die.hpp"
#include "LoadedDie.hpp"
#include "inputValidation.hpp"
#include <string>


class Game {

private:
    int p1Score, p2Score;
    bool p1IsLoaded, p2IsLoaded;
    bool quit;
    int rounds;
    Die *die;
    LoadedDie *loadedDie;
    int *p1Rolls;
    int *p2Rolls;    
    int p1Sides,p2Sides;

public:
    Game();

    bool beginMenu();

    void getInfo();
    void getRolls();

    void gameLoop();

    ~Game();
};
