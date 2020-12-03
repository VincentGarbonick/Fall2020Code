#include <cassert>
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <limits>  // numeric_limits<std::streamsize> for validations
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <initializer_list>

#include "myMemory.hpp"
#include "myString.hpp"

#ifndef MY_VECTOR_DEFINE
#define MY_VECTOR_DEFINE

class myStringVector
{
    public:
        // interface 

        // constructors 
        myStringVector();
        myStringVector(std::initializer_list<myString>); // initializer list constructor
        myStringVector(const myStringVector &); // copy constructor

        // basic functions 
        bool empty();
        int size();    

    private: 

        myString *first; // pointer to first element in vector
        myString *limit; // available memory left, for "overkilling" allocation
        myString *avail; // one past the last memory space in vector

        void printElements(myString*, myString*); // internal function for printing contents of a myStringVector
};


#endif