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
#define DEBUG_SWITCH_VECTOR (0)
#define DEEP_DEBUGGING (0)

using std::cout;
using std::endl;
 
// default destructor
myStringVector::~myStringVector()
{    
    if(size() > 0)
    {
        for(int i = 0; i < size(); i++)
        {
            destroy((first + i));
        }
    }

    if(capacity() > 0)
    {
       deallocate(first);
    }

    #if DEBUG_SWITCH_VECTOR    
        std::cout << "Destructor finished~" << std::endl;
    #endif
}

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

    #if DEEP_DEBUGGING 
        std::cout << "Size of contructed: " << (int)(avail - first) << std::endl;
        std::cout << "Max size of constructed: " << (int)(limit - first) << std::endl;
    #endif

}

// copy constructor
myStringVector::myStringVector(const myStringVector &copyVector )
{

    // allocate size 
    this->first = allocate<myString>(   (int)(copyVector.limit - copyVector.first)   ); 

    // copy what is is in list 
    this->avail = uninitialized_copy(copyVector.first, copyVector.avail, this->first);

    // get max size of vector
    this->limit = this->avail + (copyVector.avail - copyVector.first);
    

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
bool myStringVector::empty() const
{
 
    if(first == nullptr || size() == 0)
    {
        return 1; 
    }
    else 
    {
        return 0;
    }
}

// Returns the size of myStringVector
int myStringVector::size() const
{
    return ((int)(avail - first));
}

// returns total capacity of myStringVector
int myStringVector::capacity() const
{
    return ((int)(limit - first));
}

// reserves space for a myStringVector. Keep in mind that it ONLY reserves space. It does not account for elements 
// or anything else, this is best used after an empty constructor. 
// Pre: Integer for size 
// Post: none 
void myStringVector::reserve(int n)
{

    // if we already have enough size, move on     
    if(    (int)(limit -  avail) >= n   ) 
    {

    }
    // if we don't have enough size, make more, then readjust limit 
    else 
    {

        #if DEBUG_SWITCH_VECTOR
            std::cout << "Capacity before allocate is: " << capacity() << std::endl;
        #endif

        // storage for avail 
        int tempSizeAvail = size();

        // allocate more memory
        // does this add on to previosly existing space? or nah?
        first = allocate<myString>(capacity() + n);


        // "recalculate" our limit and avail
        limit = first + tempSizeAvail + n;
        avail = first + tempSizeAvail;

        #if DEBUG_SWITCH_VECTOR 
            std::cout << "Capacity after allocate is: " << capacity() << std::endl;
        #endif
    }
    


    return;
}

// resizes based on integer input, truncates all out of range elements
// Pre: integer for new size 
// Post: resized myStringVector
void myStringVector::resize(int newSize)
{
    // if we have stuff in our vector 
    if(size() > 0)
    {
        // store values in temporary vector
        myStringVector temp;
        temp.first = allocate<myString>(newSize);
        
        for(int i = 0; i < newSize; i++)
        {   
            // if we are within the bounds, store in temp
            if(i < size() && i < newSize)
            {
                *(temp.first + i) = *(first + i);
            }
        }


        // reallocate storage
        first = allocate<myString>(newSize);
        

        // copy the values stored in temp over
        for(int i = 0; i < newSize; i++)
        {            
            // if we are within the bounds, store in temp
            if(i < size() && i < newSize)
            {
                *(temp.first + i) = *(first + i);
            }
        }

        limit = avail = (first + newSize);
    }
    else // if there is nothing in our vector 
    {
        first = allocate<myString>(newSize);
        avail = limit = first + newSize;
       
        /*
        for(int i = 0; i < newSize; i++)
        {
            *(first + i) = "";
        }
        */
    }
    
    return;
} 
// classic vector function, adds a value to end of vector
// Pre: a mystring object that can be added 
// Post: Nothing 
void myStringVector::push_back(const myString& pushon)
{
    // if we have reached the end of our allocated memory
    if(avail == limit)
    {
        // resize to one extra 
        this->resize(capacity() + 1);
        *(first + capacity() +1) = pushon;
    }
    else 
    {
        // put on end of storage, increment avail
       *(avail) = pushon;
       avail++; 
    }

    return;
}

// destroys lastmost element
// Pre: none 
// Post: none 
void myStringVector::pop_back()
{
    if(size() > 0)
    {
        destroy(avail - 1);
        avail--;
    }

    return;
}


// clears all elements, but does not delete storage
// pre: none
// post: none
void myStringVector::clear()
{
    if(size() != 0)
    {
        for(int i = 0; i < size(); i++)
        {
            destroy( (first+i) );
        }
        avail = first;
    }
}
// returns pointer to first 
myString * myStringVector::begin() { return first; };

// returns pointer to avail  
myString * myStringVector::end() {return avail;}

// returns pointer to first (const version)
const myString * myStringVector::begin() const{ return first; };

// returns pointer to avail (const version)
const myString * myStringVector::end() const {return avail;}

// overloaded = operator 
// calls copy constructor unless it's an attempted self assign 
myStringVector& myStringVector::operator=(const myStringVector &copyVector)
{
    if(this == &copyVector)
    {
        std::cout << "Self assign detected. Deploying killteams." << std::endl;
    }
    else 
    {
        // allocate size 
        this->first = allocate<myString>(   (int)(copyVector.limit - copyVector.first)   ); 

        // copy what is is in list 
        this->avail = uninitialized_copy(copyVector.first, copyVector.avail, this->first);

        // get max size of vector
        this->limit = this->avail + (copyVector.avail - copyVector.first);
    }

    #if DEBUG_SWITCH_VECTOR
        std::cout << "Move/assign/equals ctor called..." << std::endl;
        printElements(first, avail);
    #endif
}

// overloaded == operator 
// return 1 for equality, 0 for no equality 
const bool myStringVector::operator==(const myStringVector & compare) const
{
    bool contentCompareFlag = 1; // 1 for yes, 0 for no
    //first compare overall size and size of populated area
    
    // IF WE HAVE THE SAME ELEMENT SIZE AND SAME OVERALL SIZE 

    #if DEEP_DEBUGGING
        std::cout << "Beginning overloaded compare..." << std::endl;
        std::cout << std::endl;
        std::cout << "Size of current: " << (int)(this->avail - this->first) << std::endl;
        std::cout << "Size of compare: " << (int)(compare.avail - compare.first) << std::endl;
        std::cout << "Max size of current: " << (int)(this->limit - this->first) << std::endl;
        std::cout << "Max size of compare: " << ((int)(compare.limit - compare.first)) << std::endl;   

    #endif 




    if(  ((int)(this->avail - this->first)==(int)(compare.avail - compare.first))  && ((int)(this->limit - this->first)==(int)(compare.limit - compare.first)) )
    {

        #if DEEP_DEBUGGING
            std::cout << "Initializing temp iterators" << std::endl;
        #endif 
        
        for(int i = 0; i < ( (int) (this->avail - this->first) ); i++)
        {

            auto tempFirst = first + i;
            auto compareFirst = compare.first + i;
            
            #if DEEP_DEBUGGING 
                std::cout << *(tempFirst->data()) << *(compareFirst->data()) << std::endl;
            #endif

            if(  *(tempFirst->data()) != *(compareFirst->data())  )
            {                
                contentCompareFlag = 0; // we found an element that is not similar 
                break; 
            }
        }

        if(contentCompareFlag)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    else 
    {
        return 0;
    }
}

// change values at index n 
myString& myStringVector::operator[](const std::size_t n) const
{

    if(n < size() && n >= 0)
    {
        // cout << *(first + n) << endl;
        return *(first + n);
    }

    else
    {
        return *(first);
    }  
}

// 1 for less than 
// 0 for greater than
bool myStringVector::operator<(const myStringVector &check) const
{
    // if the sizes are equal continue 
    if(this->size() == check.size())
    {
        if(*(this->first->data()) < *(check.first->data()))
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    // else return 0 
    else 
    {
        return 0;
    }
}

// 1 for less than 
// 0 for greater than
bool myStringVector::operator>(const myStringVector &check) const
{
    // if the sizes are equal continue 
    if(this->size() == check.size())
    {
        if(*(this->first->data()) > *(check.first->data()))
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    // else return 0 
    else 
    {
        return 0;
    }
}

// 1 for less than 
// 0 for greater than
bool myStringVector::operator<=(const myStringVector &check) const
{
    // if the sizes are equal continue 
    if(this->size() == check.size())
    {
        if(*(this->first->data()) <= *(check.first->data()))
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    // else return 0 
    else 
    {
        return 0;
    }
}

// 1 for less than 
// 0 for greater than
bool myStringVector::operator>=(const myStringVector &check) const
{
    // if the sizes are equal continue 
    if(this->size() == check.size())
    {
        if(*(this->first->data()) >= *(check.first->data()))
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    // else return 0 
    else 
    {
        return 0;
    }
}