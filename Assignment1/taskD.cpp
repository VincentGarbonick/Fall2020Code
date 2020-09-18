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

// normally this info would go in a hpp file
class Games
{
    private:

        std::string name;
        std::string type;
        float price;

    public:

        // mutator declarations 
        std::string getName();
        std::string getType();
        float getPrice();

        void setName(std::string);
        void setType(std::string);
        void setPrice(float);

        // constructor declarations 
        Games();
        Games(std::string);
        Games(float);
        Games(std::string, float);        
};




int main(void)
{
    Games game1;
    Games game2("test");
    Games game3("test", 100.11);
    Games game4(120);
}

// class definitions, normally this would go in a seperate cpp file
Games::Games()
{

}
// overload for type and price 
Games::Games(std::string overloadType, float overloadPrice)
{
    name = "No Name";
    type = overloadType;
    price = overloadPrice;
}
// overload for just price 
Games::Games(float overloadPrice)
{
    name = "No Name";
    type = "Unknown";
    price = overloadPrice;
}
// overload for initializing object with "No Name", "Uknown", and 0
// allows you to put your own message when intializing
Games::Games(std::string message)
{
    name = "No Name";
    type = "Unknown";
    price = 0.00;

    std::cout << message << std::endl;
}

// getName returns the value in the member variable name
// precondtion: no parameters
// postcondition: return the object name
std::string Games::getName()
{
    return name;
}

// getType returns the value in the member variable type
// precondtion: no parameters
// postcondition: return the object type
std::string Games::getType()
{
    return type;
}

// getPrice returns the value in the member variable price
// precondtion: no parameters
// postcondition: return the object price
float Games::getPrice()
{
    return price;
}

// setName sets the value of the member variable name
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void Games::setName(std::string sName)
{
    name = sName;
    return;
}

// setType sets the value of the member variable type
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void Games::setType(std::string sType)
{
    type = sType;
    return;
}

// setPrice sets the value of the member variable price
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void Games::setPrice(float sPrice)
{
    price = sPrice;
    return;
}