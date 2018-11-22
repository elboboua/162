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


// checks if input is an int above parameter x
int isIntAboveX(int x) {

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
               cout << "Please enter an integer above " << x << ":" << endl;
            }
        } while (!good);

        if (!(stoi(input) > x)) {

            cout << "ERROR! INCORRECT INPUT!" << endl;
            cout << "Please enter an integer above " << x << ":" << endl;
        }
    } while (!(stoi(input) > x));
    

    // return the good input
    return stoi(input);
}



// checks if input is an int above parameter x and below parameter y
int isIntBetweenXAndY(int x, int y) {

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
               cout << "Please enter an integer between " << x << " and " << y << ":" << endl;
            }
        } while (!good);

        if ( stoi(input) < x || stoi(input) > y ) {

            cout << "ERROR! INCORRECT INPUT!" << endl;
               cout << "Please enter an integer between " << x << " and " << y << ":" << endl;
        }
    } while ( stoi(input) < x || stoi(input) > y );
    

    // return the good input
    return stoi(input);
}
