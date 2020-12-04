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
        // typedefs 
        typedef myString * iterator;
        typedef const myString * const_iterator ;

        // interface 

        // constructors/destructors
        myStringVector();
        myStringVector(std::initializer_list<myString>); // initializer list constructor
        myStringVector(const myStringVector &); // copy constructor
        ~myStringVector();




        // overloads
        const bool operator==(const myStringVector &) const; //overload for ==
        myStringVector& operator=(const myStringVector &);
        myString& operator[](const std::size_t) const;
        bool operator<(const myStringVector &) const;
        bool operator>(const myStringVector &) const;
        bool operator>=(const myStringVector &) const;
        bool operator<=(const myStringVector &) const;


        // basic functions 
        bool empty() const; // is the vector empty?
        int size() const;  // how many elements are in vector?
        int capacity() const; // what is the TOTAL STORAGE CAPACITY OF VECTOR
        void clear(); // clears all elements, but does not delete storage
        
        myString * begin(); // returns pointer to first 
        myString * end(); // returns pointer to avail 
        const myString * begin() const; // returns pointer to first 
        const myString * end() const; // returns pointer to avail 
        
        // advanced functions         
        void reserve(int); // allocates space for up to INT data values 
        void resize(int); // resizes based on integer input, truncates all out of range elements
        void push_back(const myString&); // classic vector function, adds a value to end of vector
        void pop_back(); // destroys lastmost element

    private: 

        myString *first; // pointer to first element in vector
        myString *limit; // available memory left, for "overkilling" allocation
        myString *avail; // one past the last memory space in vector

        void printElements(myString*, myString*); // internal function for printing contents of a myStringVector
};


#endif