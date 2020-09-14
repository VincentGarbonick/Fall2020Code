//
//   COPYRIGHT (C) Student@zips.uakron.edu>, 2020  All rights reserved.
//   Student Name
//   Purpose: This is myCode and is based upon what we study for Comp Sci
//
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <limits>  // numeric_limits<std::streamsize> for validations
#include <memory>
#include <vector>
#include <cstring>

int gSIZE = 10;

char * deleteRepeat(char*);
bool checkIllegal(char, std::vector<char>);

int main(void)
{
    char * repeatArray = new char [gSIZE]; 
    * repeatArray = 'a';
    * (repeatArray + 1)= 'a';
    * (repeatArray + 2)= 'n';
    * (repeatArray + 3)= 'a';
    * (repeatArray + 4)= 'a';
    * (repeatArray + 5)= 'q';
    * (repeatArray + 6)= 'a';
    * (repeatArray + 7)= 'a';
    * (repeatArray + 8)= 'a';
    * (repeatArray + 9)= 'z';
    
    char * newArray = deleteRepeat(repeatArray);
    // std::cout << *(repeatArray) << std::endl;

    return 0;
}

char * deleteRepeat(char * pOriginalCharArray)
{


    char * pNewCharArray; // pointer to new character array
    int newSize = 0; // size of the new array we are going to get 
    std::vector<char> illegalChar; // where we store the chracters that already exist in the dynamic array
    char dereferencedChar;
    bool foundCharFlag;

    // go through each element in the original array
    for(int i =0; i < gSIZE; i++)
    {

        foundCharFlag = checkIllegal(*pOriginalCharArray, illegalChar);

        if(foundCharFlag == true)
        {
            // do nothing and ignore
        }
        // if we did not find the character in the illgal array, that means it's not a repeat and we can add it to the illegal array
        else if(foundCharFlag == false)
        {
            illegalChar.push_back(*pOriginalCharArray);
            newSize++;
        }

        pOriginalCharArray++;
    };

    // allocate memory for new character array
    pNewCharArray = new char [illegalChar.size()];

    // copy values over from illegalchar
    for(int i = 0; i < illegalChar.size(); i++)
    {
        *(pNewCharArray + i)= illegalChar[i];
    }

    return pNewCharArray;
}

// function for checking if the original array has a character in the "illegal characters" vector
// Precondition: character to look for and vector of "illegal characters"
// Postcondition: true for found, false for not found
bool checkIllegal(char checkChar, std::vector<char> checkVector)
{
    bool foundflag;

    // loop through vector and look for character
    for(int i = 0; i < checkVector.size(); i++)
    {
        // if we find  the character in the vector, break out of the loop and set flag to true 
        if(checkVector[i] == checkChar)
        {
            foundflag = true;
            break;
        }        
    }

    return foundflag;
}