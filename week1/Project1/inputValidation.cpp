/********************************************************************* 
** Description: Implementation file for Input validation function(s)
*********************************************************************/

#include <string>
using std::string;
using std::stoi;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


// checks if input is an int above zero
int isIntAboveZero() {

    string input;
    bool good;

    // two do while functions that check if the input is a digit and if it is above 0
    do {
        do  {
            
            good = true;

            cin >> input;
            
            // goes through each element in the string to see if it is a digit
            for (int i = 0; i < input.length(); i++) {

                
                if (!(isdigit(input[i]))) {
                    good = false;
                } 
            }
            if (!good) {
               cout << "ERROR! INCORRECT INPUT!" << endl;
               cout << "Please enter an integer above 0:" << endl;
            }
        } while (!good);

        if ((stoi(input) < 1)) {

            cout << "ERROR! INCORRECT INPUT!" << endl;
            cout << "Please enter an integer above 0:" << endl;
        }
    } while (stoi(input) < 1);
    

    // return the good input
    return stoi(input);
}


// This function validates the input for the starting location of the ant.
int startPosVal(int size) {

    string input;
    bool good;

    
    // two do while functions that check if the input is a digit and if it is above 0 and smaller than the parameter variable.
    do {
        do  {
            
            good = true;

            cin >> input;
            
            // goes through each element in the string to see if it is a digit
            for (int i = 0; i < input.length(); i++) {

                
                if (!(isdigit(input[i]))) {
                    good = false;
                } 
            }
            if (!good) {
               cout << "ERROR! INCORRECT INPUT!" << endl;
               cout << "Please enter an integer above 0 and smaller than " << size << ":" << endl;
            }
        } while (!good);

        if (stoi(input) < 1 || stoi(input) > size) {

            cout << "ERROR! INCORRECT INPUT!" << endl;
            cout << "Please enter an integer above 0 and smaller than " << size << ":" << endl;
        }
    } while (stoi(input) < 1 || stoi(input) > size);
 

    // return the good input
    return stoi(input);





}
