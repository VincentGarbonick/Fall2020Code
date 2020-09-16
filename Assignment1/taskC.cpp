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
#include <string>
#include <cstring>
#include <stdio.h>

int gSIZE = 10;

void (* callIt(std::string))();

// prototypes for callback functions 
void yellow();
void red();
void purple();
void blue();
void white();
void green();

int main(void)
{
    void (*callbackPointer)();
    
    callbackPointer = callIt("Colonel Mustard");    
    if(callbackPointer != nullptr ){callbackPointer();}
    
    callbackPointer = callIt("Rev Green");    
    if(callbackPointer != nullptr ){callbackPointer();}

    return 0;
}

// returns a function pointer based on input string 
// precondition: input string 
// postcondition: a function pointer to a certain function
void (* callIt(std::string name))()
{
    void (* pCallbackPointer)(); 

    if(name == "Colonel Mustard")
    {
        pCallbackPointer = yellow;
    }
    else if(name == "Miss Scarlet")
    {
        pCallbackPointer = red;
    }
    else if(name == "Professor Plum")
    {
        pCallbackPointer = purple;
    }
    else if(name == "Mrs. Peacock")
    {
        pCallbackPointer = blue;
    }
    else if(name == "Mrs. White")
    {
        pCallbackPointer = white;
    }
    else if(name == "Rev Green")
    {
        pCallbackPointer = green;
    }
    else 
    {
        std::cout << "Invalid input type.." << std::endl;
        pCallbackPointer = nullptr;
    }

    return pCallbackPointer;
}

// returns the color stated in the function name 
// precondition: none 
// postcondition: none
void yellow()
{
    std::cout << "Colonel Mustard is yellow." << std::endl;
    return;
}

// returns the color stated in the function name 
// precondition: none 
// postcondition: none
void red()
{
    std::cout << "Miss Scarlet is red." << std::endl;
    return;
}

// returns the color stated in the function name 
// precondition: none 
// postcondition: none
void purple()
{
    std::cout << "Professor Plum is purple." << std::endl;
    return;
}

// returns the color stated in the function name 
// precondition: none 
// postcondition: none
void blue()
{
    std::cout << "Mrs. Peacock is blue." << std::endl;
    return;
}

// returns the color stated in the function name 
// precondition: none 
// postcondition: none
void white()
{
    std::cout << "Mrs. White is white." << std::endl;
    return;
}

// returns the color stated in the function name 
// precondition: none 
// postcondition: none
void green()
{
    std::cout << "Rev Green is green." << std::endl;
    return;
}