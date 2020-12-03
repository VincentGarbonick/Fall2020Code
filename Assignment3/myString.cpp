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
#include <cstring>


#include "myString.hpp"


#define DEBUG_SWITCH_STRING (0)

//Global constants

// *************************************************
// PLACE ALL OF THIS PROGRAM'S prototypes and Declarations here
//
// This code would normally go into a dot hpp file
//
// SPECIFICATION HERE
//
// PLACE CODE HERE FOR TASK A
// *************************************************



// this constructor is for initializing an empty "mystring"
myString::myString()
{
  strLength = 0;
  stringVar = new char[1];
  *stringVar = '\0';
}


// this constructor is for initializing "mystring" with a const char*
myString::myString(const char* cPointer)
{
  if(cPointer != NULL)
  {  

    // count length of string
    strLength = 0;
    while(*(cPointer + strLength) != '\0')
    {
      strLength++;
    } 

    // dynamically allocate space for stringVar
    stringVar = new char[strLength + 1]; // add extra space for null terminator

    // copy contents over, including terminator we do that by using equals 
    for(int i = 0; i <= strLength; i++)
    {
      *(stringVar + i) = *(cPointer + i);
      // std::cout << *(stringVar +i) << std::endl;
    }

    #if DEBUG_SWITCH_STRING  
      std::cout << stringVar << std::endl;
    #endif
  
  }

  return;
}

// copy constructor 
myString::myString(const myString &copyMyString)
{ 
  strLength = copyMyString.size();

  stringVar = new char[strLength + 1];

  for(int i = 0; i <= strLength; i++)
  {
    *(stringVar + i) = *(copyMyString.data() + i);
  }
  #if DEBUG_SWITCH_STRING
    std::cout << "copied: " <<  stringVar << std::endl;
  #endif
}

// this constructor is for initializing only PART of a string, based on given size
// remember, strings must be null terminated
myString::myString(const char * cPointer, size_t size)
{
  this->strLength = size;

  this->stringVar = new char[strLength + 1];

  for(int i = 0; i < this->strLength; i++)
  {
    *(this->stringVar + i) = *(cPointer + i);
  }

  // add null terminator
  *(this->stringVar + size) = '\0';
  
  #if DEBUG_SWITCH_STRING
    std::cout << "Partial init: " << stringVar << std::endl;
  #endif
}

myString& myString::operator=(const char* copyString)
{
  
  int tempLength = 0;

  while(*(copyString + tempLength) != '\0')
  {
    tempLength++;
  }

  // size for new string pointer
  this->strLength = tempLength;

  // contents for new string 
  this->stringVar = new char[tempLength + 1];

  for(int i = 0; i <= strLength; i++)
  {
      *(this->stringVar + i) = *(copyString + i);
  }

  #if DEBUG_SWITCH_STRING
    std::cout << "Equals assignement operator used (literal): " << this->stringVar << std::endl;
  #endif

  return *this;
}

myString& myString::operator=(const myString &oldString)
{
  if(this != &oldString)
  {
  this->strLength = oldString.size();

  this->stringVar = new char[this->strLength + 1];

  for(int i = 0; i <= this->strLength; i++)
  {
    *(this->stringVar + i) = *(oldString.data() +i);
  }

  #if DEBUG_SWITCH_STRING
    std::cout << "Equals assignement operator used (object): " << this->stringVar << std::endl;
  #endif

  }
  else 
  {
    std::cout << "Self assignement detected..." << std::endl;
  }
  return *this;

}

 myString& myString::operator+=(const myString &oldString)
 {

  char * tempThisInfo = new char[this->size() + 1];
   
  for(int i = 0; i <= this->size(); i++)
  {
    *(tempThisInfo + i) = *(this->data() + i);
  }

  int oldThisSize = this->size();
   
  this->strLength = this->strLength + oldString.strLength;
  
  this->stringVar = new char[strLength + 1];

  for(int i = 0; i < oldThisSize; i++)
  {
    *(this->data() + i) = *(tempThisInfo + i);
  }

  int j = 0;
  for(int i = oldThisSize; i <= this->strLength; i++)
  {
    *(this->data() + i) = *(oldString.stringVar + j);
    j++;
  }

  #if DEBUG_SWITCH_STRING
    std::cout << "Plus Equals assignement operator used (object): " << this->stringVar << std::endl;
  #endif

  return *this;
 }

// change values at index n 
char& myString::operator[](const std::size_t n)
{
  if(n < size() && n >= 0)
  {
    return *(this->stringVar + n);
  }

  else
  {
    return *(this->stringVar);
  }  
}

const char&  myString::operator[](std::size_t n) const
{
  if(n < size() && n >= 0)
  {
    return *(this->stringVar + n);
  }

  else
  {
    return *(this->stringVar);
  }  
}

/*
  // ordering. One string compares less than another when it lexicographically
  // precedes it. Hint: see std::strcmp
  {
    myString s1 = "abc";
    myString s2 = "def";
    assert(s1 < s2);
    assert(s2 > s1);
    assert(s1 <= s1);
    assert(s1 >= s1);
  }


    myString operator+(myString &) const; //overloading + operator
    myString& operator=(myString &&); //move assignment operator
*/

myString myString::operator+(myString &fusion) const 
{
  short newSize = this->strLength + fusion.size();
  char * newStringVar = new char[newSize +1];

  int secondaryIncrement = 0;

  for(int i = 0; i < newSize; i++)
  {
    if(i < this->strLength)
    {
      newStringVar[i] = *(this->data() + i);
    }
    else if(i >= this->strLength && i < newSize)
    {
      newStringVar[i] = *(fusion.data() + secondaryIncrement);
      secondaryIncrement++; 
    }
  }

  return myString(newStringVar);
}

/*
comparing operators works in the following way 
the function starts comparing the first character of each string. if they are equal to eachotehr, it continues with the 
following pairs until the characters differ or until a terminating null character is reached
*/
// 0 - the condition evaluates to false  or unable to evaluate 
// 1- the condition evealuates to true 
bool myString::operator>=(myString &compare) const //overloading < comparison operator
{
  // they must be equal in size
  if(this->size() == compare.size())
  {
    bool foundOperator = 0; //1 - we satisfied the condition  0- nope!
    int i = 0;
    while(i < this->size())
    {
      if(   *(stringVar + i)    >= *(compare.data() + i) &&   *(stringVar + i ) != '\0')
      {
        foundOperator = 1;
        break;
      }
      i++;
    }

    if(foundOperator)
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "Satisfied for " << stringVar << ">=" << compare.data() << std::endl;
      #endif
      return 1;
    }
    else 
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "NOT satisfied for " << stringVar << ">=" << compare.data() << std::endl;
      #endif

      return 0;
    }
  }
  else 
  {
    #if DEBUG_SWITCH_STRING
      std::cout << "Strings are not the same size, cannot be done." << std::endl;
    #endif

    return 0;
  }
}
bool myString::operator>=(const char * charP)  //overloading < comparison operator
{

    bool foundOperator = 0; //1 - we satisfied the condition  0- nope!
    int i = 0;
    while(i < this->size())
    {
      if(   *(stringVar + i)    >= *(charP + i) &&   *(stringVar + i ) != '\0')
      {
        foundOperator = 1;
        break;
      }
      i++;
    }

    if(foundOperator)
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "Satisfied for " << stringVar << ">=" << charP << std::endl;
      #endif

      return 1;
    }
    else 
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "NOT satisfied for " << stringVar << ">=" << charP << std::endl;
      #endif
      
      return 0;
    }
  }
bool myString::operator>(myString &compare) const //overloading < comparison operator
{
  // they must be equal in size
  if(this->size() == compare.size())
  {
    bool foundOperator = 0; //1 - we satisfied the condition  0- nope!
    int i = 0;
    while(i < this->size())
    {
      if(   *(stringVar + i)    > *(compare.data() + i) &&   *(stringVar + i ) != '\0')
      {
        foundOperator = 1;
        break;
      }
      i++;
    }

    if(foundOperator)
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "Satisfied for " << stringVar << ">" << compare.data() << std::endl;
      #endif

      return 1;
    }
    else 
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "NOT satisfied for " << stringVar << ">" << compare.data() << std::endl;
      #endif

      return 0;
    }
  }
  else 
  {
    #if DEBUG_SWITCH_STRING
      std::cout << "Strings are not the same size, cannot be done." << std::endl;
    #endif

    return 0;
  }
}
bool myString::operator>(const char * charP)  //overloading < comparison operator
{

    bool foundOperator = 0; //1 - we satisfied the condition  0- nope!
    int i = 0;
    while(i < this->size())
    {
      if(   *(stringVar + i)    > *(charP + i) &&   *(stringVar + i ) != '\0')
      {
        foundOperator = 1;
        break;
      }
      i++;
    }

    if(foundOperator)
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "Satisfied for " << stringVar << ">" << charP << std::endl;
      #endif

      return 1;
    }
    else 
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "NOT satisfied for " << stringVar << ">" << charP << std::endl;
      #endif

      return 0;
    }
  }

bool myString::operator<(const char * charP)  //overloading < comparison operator
{

    bool foundOperator = 0; //1 - we satisfied the condition  0- nope!
    int i = 0;
    while(i < this->size())
    {
      if(   *(stringVar + i)    < *(charP + i) &&   *(stringVar + i ) != '\0')
      {
        foundOperator = 1;
        break;
      }
      i++;
    }

    if(foundOperator)
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "Satisfied for " << stringVar << "<" << charP << std::endl;
      #endif

      return 1;
    }
    else 
    {
      #if DEBUG_SWITCH_STRING
      std::cout << "NOT satisfied for " << stringVar << "<" << charP << std::endl;
      #endif 

      return 0;
    }
  }

bool myString::operator<(myString &compare) const //overloading < comparison operator
{
  // they must be equal in size
  if(this->size() == compare.size())
  {
    bool foundOperator = 0; //1 - we satisfied the condition  0- nope!
    int i = 0;
    while(i < this->size())
    {
      if(   *(stringVar + i)    < *(compare.data() + i) &&   *(stringVar + i ) != '\0')
      {
        foundOperator = 1;
        break;
      }
      i++;
    }

    if(foundOperator)
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "Satisfied for " << stringVar << "<" << compare.data() << std::endl;
      #endif 
      
      return 1;
    }
    else 
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "NOT satisfied for " << stringVar << "<" << compare.data() << std::endl;
      #endif

      return 0;
    }
  }
  else 
  {
    #if DEBUG_SWITCH_STRING
      std::cout << "Strings are not the same size, cannot be done." << std::endl;
    #endif

    return 0;
  }
}
bool myString::operator<=(myString &compare) const //overloading < comparison operator
{
  // they must be equal in size
  if(this->size() == compare.size())
  {
    bool foundOperator = 0; //1 - we satisfied the condition  0- nope!
    int i = 0;
    while(i < this->size())
    {
      if(   *(stringVar + i)    <= *(compare.data() + i) &&   *(stringVar + i ) != '\0')
      {
        foundOperator = 1;
        break;
      }
      i++;
    }

    if(foundOperator)
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "Satisfied for " << stringVar << "<=" << compare.data() << std::endl;
      #endif

      return 1;
    }
    else 
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "NOT satisfied for " << stringVar << "<=" << compare.data() << std::endl;
      #endif

      return 0;
    }
  }
  else 
  {
    #if DEBUG_SWITCH_STRING
      std::cout << "Strings are not the same size, cannot be done." << std::endl;
    #endif
    
    return 0;
  }
}
bool myString::operator<=(const char * charP)  //overloading < comparison operator
{

    bool foundOperator = 0; //1 - we satisfied the condition  0- nope!
    int i = 0;
    while(i < this->size())
    {
      if(   *(stringVar + i)    <= *(charP + i) &&   *(stringVar + i ) != '\0')
      {
        foundOperator = 1;
        break;
      }
      i++;
    }

    if(foundOperator)
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "Satisfied for " << stringVar << "<=" << charP << std::endl;
      #endif

      return 1;
    }
    else 
    {
      #if DEBUG_SWITCH_STRING
        std::cout << "NOT satisfied for " << stringVar << "<=" << charP << std::endl;
      #endif
      
      return 0;
    }
  }
// -------------------------end of compare operators------------------------------------------
// return 1 for not equal, 0 for equal 
const bool myString::operator!=(const myString &compare) const
{
  if(strLength == compare.size())
  {
    return 1; 
  }
  else 
  {
    bool contentCompareFlag = 1; 
    int countSameChar = 0; 
    for(int i = 0; i < this->strLength; i++)
    {
      if(*(this->stringVar + i) == *(compare.data() + i))
      {
        // if the number of characters that 
        countSameChar++; // increment count same char
      }
    }
    if(countSameChar == strLength)
    {
      return 0;
    }
    else 
    {
      return 1; 
    }
  }
}

// return 1 for they are equal, 0 for not
const bool myString::operator==(const myString &compare) const
{
  if(this->strLength && compare.size())
  {
    bool contentCompareFlag = 1; // 1 for yes, 0 for no
    for(int i = 0; i < this->strLength; i++)
    {
      if(*(this->stringVar + i) != *(compare.data() + i))
      {
        contentCompareFlag = 0;
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
char* myString::substr(std::size_t p1, std::size_t p2) const
{
  
  if(p1 < strLength && p1+p2 <= strLength)
  {
    size_t tempSize = p2;
    char * newBuffer = new char[p2  + 1]; // adding one for null terminator  

    for(int i = 0; i < p2; i++)
    {
       *(newBuffer + i) = *(stringVar + p1 + i);
    }

    *(newBuffer + p2 + 1) = '\0'; // null terminate it


    return newBuffer; 
  }
  else 
  {

    char * junkBuffer = new char[1];
    *(junkBuffer) = '\0';

    return junkBuffer;
  }
}
// find first instance of a character
std::size_t myString::find(char findChar) const
{
  bool findFlag = 0; //false 0, true 1
  int findPos; 

  for(int i = 0; i < this->strLength; i++)
  {
    if(*(this->stringVar + i) == findChar)
    {
      findFlag = 1; 
      findPos = i;
      break;
    }
  }

  if(findFlag)
  {
    return findPos; 
  }
  else 
  {
    return this->npos;
  }

}
size_t myString::size() const
{
  return strLength;
}

bool myString::empty() const
{
  if(*stringVar == '\0' && strLength == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  
}

char* myString::data() const
{
  return stringVar;
}

std::ostream& operator<<(std::ostream& input, myString const& rhs)
{
    input << rhs.stringVar;
    return input;
}
