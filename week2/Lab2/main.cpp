/*********************************************************************
** Author: Ahmad El-Bobou
** Date: 10-07-2018 
** Description: Lab2 - I/O practice 
*********************************************************************/

#include "count_letters.hpp"
#include "output_letters.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <fstream> 
using std::ifstream;
using std::ofstream;

// This program takes input from a text file and outputs the letter frequency information for each paragraph
// to a user specified output file. 
int main () {
 

    // Creating array for the alphabet frequency   
    const int ALPHABET = 26;
    int frequency[ALPHABET];



    // Getting file from which to pull data
    string inputFile;

    cout << "Please enter the name of a file to read from:" << endl;
    cin >> inputFile;    

    // Creating ifstream object;
    ifstream ifs(inputFile.c_str());
    
    // Checking for errors opening file
    if (!ifs) {
        cout << "There has been an error opening your input file." << endl;
        return -1;
    }

    // Loop that iterates until all paragraphs have been read. 
    while (!ifs.eof()) {

        // Clears the array 
        for (int i = 0; i < ALPHABET; i++) {
            frequency[i] = 0;
        }


        count_letters(ifs, frequency);

        ofstream ofs;

        output_letters(ofs, frequency);
    };


    return 0;

}
