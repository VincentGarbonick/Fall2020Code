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


#include "myStringVector.hpp"

// preprocessor switch for debugging 
#define DEBUG_SWITCH_VECTOR (1)

// default constructor
myStringVector::myStringVector()
{
    first = nullptr;
    avail = nullptr;
    limit = nullptr;
}

// initializer list constructor 
myStringVector::myStringVector(std::initializer_list<myString> list)
{

    // allocate first half of space  
    first = allocate<myString>(    (int)  (list.size() * 2)  ); // allocate double the space of the initializer list 

    // copy what is in list 
    avail = uninitialized_copy(list.begin(), list.end(), first);

    // get max size of vector
    limit = avail + list.size();

    #if DEBUG_SWITCH_VECTOR
        std::cout << "List init called..." << std::endl;
        printElements(first, avail);
    #endif

}

// copy constructor
myStringVector::myStringVector(const myStringVector &copyVector )
{
    // allocate size 
    this->first = allocate<myString>(   (copyVector.limit - copyVector.first)   ); 

    // copy what is is in list 
    this->avail = uninitialized_copy(copyVector.first, copyVector.avail, this->first);

    // get max size of vector
    this->limit = this->avail + (copyVector.limit - copyVector.first);


    #if DEBUG_SWITCH_VECTOR
        std::cout << "Copy ctor called..." << std::endl;
        printElements(first, avail);
    #endif
}

// prints off elements stored in vector
// Pre: Valid iterators for first and avail 
// Post: Nothing
void myStringVector::printElements(myString* first, myString* avail)
{
    while(first != avail)
    {
        std::cout << *first << std::endl; 
        first++;
    }
}

// Returns 1 if empty, 0 if not empty 
// Pre: None 
// Post: Bit signifying full-status
bool myStringVector::empty()
{
    if(first == nullptr)
    {
        return 1; 
    }
    else 
    {
        return 0;
    }
}

// Returns the size of myStringVector
int myStringVector::size()
{
    return (int)(avail - first);
}