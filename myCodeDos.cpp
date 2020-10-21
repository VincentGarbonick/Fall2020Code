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



class myString
{
  public:

    myString(); // Default construction; the default value shall be the empty string.

    myString(const char* ); //for initializing with a string
    //Pre: pointer must not be a null pointer
    //Post: will initialize an object to a string literal

    
    myString(const char*, std::size_t); //initialization by part of a string literal
    //Pre: c-string must not be null and have size charAmount
    //Post: will initialize object to the charAmount of characters in a string literal

    
    myString(const myString &); //copy constructor initializer
    //Pre: must accepts an object of the same type
    //Post: The initialized object will be equal to the original

    /*
    myString(myString &&); //move constructor
    */

    bool empty() const; //empty function to tell if a string is empty or not
    //Pre: none
    //Post: returns 1 for true and 0 for false and does not change string (1 is empty, 0 is not empty)
    
    
    std::size_t size() const; //size() function to return the length of a string
    //Pre: none
    //Post: return the lenght of a string not including the null terminator (does not change the string)
    
    
    char* data() const; //returns a raw c-string pointer
    //Pre: none
    //Post: returns a char pointer that holds the c-string

    
    std::size_t find(char ) const; //returns the index of the first occurrence of the target char
    //Pre: accepts a valid char for the target the user wants to find
    //Post: returns index where the target first occurs or npos if not found

    
    char* substr(std::size_t, std::size_t) const; //makes a string out of an existing string
    //Pre: accepts a integer for the index to start at and charAmount for the amount of characters
    //Post: returns a char pointer for the new substring
    
    // friend std::ostream& operator<<(std::ostream&, myString const&); //overload << operator to output stringVar
    

    
    myString& operator=(const char*); //overload assignment operator to take string literal
    myString& operator=(const myString &); //overload assignment operator to take in an object of the same type
    myString& operator+=(const myString &); //overload operator for the concatenation    
    char& operator[](const std::size_t ); //overload operator [] to return values and change values at index n
    const char& operator[](std::size_t ) const; //const version of [] overload
    
    const bool operator==(const myString &) const; //overload for ==
    const bool operator!=(const myString &) const; //overload for !=
    
    /*
    bool operator<(myString &) const; //overloading < comparison operator
    bool operator<(const char *); //overloading < comparison operator for string literal
    bool operator<=(myString &) const; //overloading <= comparison operator
    bool operator<=(const char *); //overloading <= comparison operator for string literal
    bool operator>(myString &) const; //overloading > comparison operator
    bool operator>(const char *); //overloading > comparison operator for string literal
    bool operator>=(myString &) const; //overloading >= comparison operator
    bool operator>=(const char *); //overloading >= comparison operator for string literal
    myString operator+(myString &) const; //overloading + operator
    myString& operator=(myString &&); //move assignment operator
    // add a test case for move construction and assignment and EARN B O N U S points!!!


    ~myString() //deconstructor
    {
        delete [] stringVar;
        stringVar = nullptr;
    }
    */
    // Defines the npos value.
    static constexpr std::size_t npos = -1;

  private:

    // counts the size of our string, for internal use only 
    // pre: a valid, non null character pointer
    // post: integer value representing the size of the contents
    short countString(char *);
    short countString(const char *); // overload for constant characters

    // this holds the contents of the "cstring"
    char* stringVar;
    // this holds the length of the "cstring"
	  short strLength;
};


// PLACE CODE HERE FOR TASK B
// *************************************************
// constant size and the overloaded function reverse
const size_t mySize = 25;
void reverse1(char *);
void reverse2(bool *);
void reverse3(short *);

// PLACE CODE HERE FOR TASK C
// *************************************************

// PLACE CODE HERE FOR TASK D
// *************************************************

// PLACE CODE HERE FOR TASK E
// *************************************************
//---------------------------------------------------------------------
// Employee class definition
class Employee
{
  public:
    Employee()
    {
      firstName = " ";
      lastName = " ";
    }
   // Employee constructor initializes the three data members
   Employee(std::string first, std::string last, int salary)
    : firstName{first}, lastName{last}
   {
      if (salary >= 0)
      { // if salary is valid
         monthlySalary = salary; // set monthlySalary to salary
      }
   }

   // set first name
   void setFirstName(const std::string &);
   // return first name
   std::string getFirstName();
   // set last name
   void setLastName(const std::string &);
   // return last name
   std::string getLastName();
   // set monthly salary; if not positive, set to 0
   void setMonthlySalary(int);
   // return monthly salary
   int getMonthlySalary();

  private:
   std::string firstName; // Employee's first name
   std::string lastName; // Employee's last name
   int monthlySalary{0}; // Employee's salary per month
};
//---------------------------------------------------------------------

// these are declarations - prefer this or std:: prefix
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;

static int uChoose = 0;

int
mainMenu();

void
taskA();

void
taskA();

void
taskB();

void
taskC();

void
taskD();

void
taskE();

struct Test_myCode
{
  void
  default_beg()
  {
    uChoose = mainMenu();
    assert(!(std::cin.fail()));
    std::cout << " Main menu passed " << std::endl;
  }
  void
  whatAction()
  {
    switch (uChoose)
    {
      case (1):
        taskA();
        break;
      case (2):
        taskB();
        break;
      case (3):
        taskC();
        break;
      case (4):
        taskD();
        break;
      case (5):
        taskE();
        break;
      case (6):
        //taskF();
        break;
      case (7):
        //taskG();
        break;
      case (8):
        //taskH();
        break;
      default:
        cout << "no case";
    }
  }

  // The test runner for this test class.
  void
  run()
  {
    default_beg();
    whatAction();
  }

};


int
main()
{
  Test_myCode test;
  while (true)
  {
    test.run();
  }

}



int
mainMenu()
{
  // heading, input section
  cout << endl;
  cout << setw(68) << "__________________________________________________________________ " << endl;
  cout << setw(68) << "|------------------------------------------------------------------|" << endl;
  cout << setw(68) << "|                Your Name - My Programming World                  |" << endl;
  cout << setw(68) << "|                  Excellently coded solutions                     |" << endl;
  cout << setw(68) << "|__________________________________________________________________|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "   MAIN MENU"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "1) Task A"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "2) Task B"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "3) Task C"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "4) Task D"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "5) Task E"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "6) Open"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "7) Open"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "8) Open"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "Ctrl-c to Quit"
       << right << setw(2) << "|" << endl;
  cout << setw(68) << "|__________________________________________________________________|" << endl;
  cout << endl;
  int userChoice = 0;
  // take and validate the user entry

  cout << "Enter the code that you wish to generate, or quit to exit: "; // output stream a message
  cin >> userChoice;
  return userChoice;
}

void
taskA()
{
  // Check the default contsructor (ctor).
  {
    myString s;
    assert(s.empty());
  }
  // A member function to return the length of the string.
  // Returns a std::size_t (unsigned integer) value. The size() function
  // shall not modify the object s1.
  //
  // This operation shall be constant time (i.e., you cannot traverse the
  // underlying string to compute the length).
  {
    myString s1 = "hola";
    std::size_t n = s1.size();
  }

  
  // string ctor
  {
    char const* str = "hello";
    myString s = str;
    assert(s.data() != str);
    assert(strcmp(s.data(), str) == 0);
  }

  
  // Raw C-string access, which returns the underlying array of
  // characters as a pointer. This member function shall not modify its
  // object.
  {
    myString s1 = "hola";
    char const* p1 = s1.data();
  }

  
  // copy ctor
  // Initialization by a string literal. The initialized object (s1)
  // shall be equal to the string literal after initialization.
  // The string literal shall not be a null pointer. You must assert
  // this property.
  // Copy construction. The initialized object (s2) shall be equal to
  // the original (s1) after initialization.
  {
    myString s1 = "hello";
    myString s2 = s1;
    assert(strcmp(s1.data(), s2.data()) == 0);
  }

  
  // Initialization by a bounded C-string. The initialized object (s2)
  // shall be equal to the first n characters of the given C-string.
  // The C-string shall not be null and shall have at least length n.
  // You must assert this property. Hint: use std::strnlen and be aware
  // that it may not insert a null-terminator.
  {
    myString s2("yolo", 2); // s2 is equal to "yo".
    assert(!strcmp(s2.data(), "yo"));
  }

  
  // Copy assignment. After assignment, the assigned object on the left (s1)
  // shall be equal to the value on the right (s2).
  {
    myString s1 = "hello";
    myString s2;
    s2 = s1;
    assert(strcmp(s1.data(), s2.data()) == 0);
    // Compound addition/assignment (concatenation). Appends the string s2
    // to s1.
    s1 += s2;
  }
  
  // Assignment to a string. After assignment, the object on the left (s1)
  // shall be equal to the string literal on the right.
  {
    myString s1;
    s1 = "hello";
    assert(!strcmp(s1.data(), "hello"));
  }

  
  // self assign
  {
    myString s1 = "hello";
    s1 = s1;
  }
  
  // A member function to determine if a string is empty. Returns true
  // if s1 is the empty string. The empty() function shall not modify
  // the object s1 (i.e., the member function must be const).
  {
    myString const s1;
    assert(s1.empty());
    myString const s2 = "";
    assert(s2.empty());
  }

  
  // Character access. Support reading and writing of characters using
  // the subscript operator. Both operators take a std::size_t argument n,
  // such that n >= 0 and n < size(). You must assert that the index is
  // in bounds.
  {
    myString s1 = "hello";
    s1[0] = 'a';
    assert(s1[0] == 'a');

    myString const s2 = "test";
    assert(s2[0] == 't');

    assert(s1[-1]);
    assert(s2[-1]);
  }

  
  // A member function that returns the index of the first character
  // in the string. This shall return a std::size_t value. If no such
  // character exists, return npos. Hint: see std::strchr.
  //
  // Note that npos is already defined within your class.
  //
  // This function shall not modify its object.
  {
    myString const s1 = "abcdef";
    assert(s1.find('c') == 2);
    assert(s1.find('z') == s1.npos);
  }

  
  // A member function that creates a substring comprising all of the
  // characters starting at an index i and containing n characters. The
  // index i shall be a valid position in the string. You must assert
  // this condition. If n is larger than the number of characters past i
  // then all characters after i are copied to the the output.
  // Hint: use your bounded C-string constructor.
  //
  // This function shall not modify its object.
  {
    myString const s1 = "abcdef";
    myString s2 = s1.substr(0, 3);
    myString s3 = s1.substr(3, 3);
    assert (s2 == "abc");
    assert (s3 == "def");
  }

  /*
  // Equality comparisons. Two strings compare equal when they have the
  // same sequence of characters. Hint: see std::strcmp.
  {
    myString const s1 = "hello";
    myString const s2 = "goodbye";
    assert(s1 == s1);
    assert(s1 != s2);
  }

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

  // concatenation
  {
    myString s1 = "abc";
    myString s2 = "def";
    myString s3 = s1 + s2;
    myString s4 = "abcdef";
    assert(s3 == s4);
  }

  // self concatenation
  {
    myString s1 = "abc";
    s1 += s1;
    myString s2 = "abcabc";
    assert(s1 == s2);
  }
  */
  cout << "end of task A" << endl;
  cin.get();
}


void
taskB()
{
  std::cout << "task B" << std::endl;
  /*
// these are the test cases
  char str1[]  = "sriahc gab naeb evah emos";
  bool str2[]  = {0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
  short str3[] = {99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75};

  cout << " *** - Separate Reverse Functions - ***" << endl << endl;
  cout << "The arrays before and after reversing: " << endl;
  cout << " array1: " << str1 ;
  reverse1(str1);
  cout << endl << " array1: " << str1 << endl;
  cout << " array2: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str2[i] << " " ;
  }
  reverse2(str2);
  cout << endl;

  cout << " array2: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str2[i] << " " ;
  }
  cout << endl;

  cout << " array3: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str3[i] << " " ;
  }
  cout << endl;

  reverse3(str3);
  cout << " array3: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str3[i] << " " ;
  }
  cout << endl;
  */
  cout << "end of task B" << endl;
  cin.get();
}

void
taskC()
{

  std::cout << "task C" << std::endl;
  /*
// these are the test cases
  char str1[]  = "sriahc gab naeb evah emos";
  bool str2[]  = {0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
  short str3[] = {99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75};

  cout << "*** - Overloaded Reverse Functions - ***" << endl << endl;
  cout << "The arrays before and after reversing: " << endl;
  cout << " array1: " << str1 ;
  reverse(str1);
  cout << endl << " array1: " << str1 << endl;
  cout << " array2: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str2[i] << " " ;
  }
  reverse(str2);
  cout << endl;

  cout << " array2: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str2[i] << " " ;
  }
  cout << endl;

  cout << " array3: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str3[i] << " " ;
  }
  cout << endl;

  reverse(str3);
  cout << " array3: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str3[i] << " " ;
  }
  cout << endl;

  cout << endl;
  */
  cout << "end of task C" << endl;
  cin.get();
}

void
taskD()
{
  std::cout << "task D" << std::endl;
  /*
// these are the test cases
  char str1[]  = "sriahc gab naeb evah emos";
  bool str2[]  = {0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
  short str3[] = {99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75};

  cout << "*** - A Templated Reverse Function - ***" << endl << endl;
  cout << "The arrays before and after reversing: " << endl;
  cout << " array1: " << str1 ;
  reversal(str1);
  cout << endl << " array1: " << str1 << endl;
  cout << " array2: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str2[i] << " " ;
  }
  reversal(str2);
  cout << endl;

  cout << " array2: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str2[i] << " " ;
  }
  cout << endl;

  cout << " array3: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str3[i] << " " ;
  }
  cout << endl;

  reversal(str3);
  cout << " array3: ";
  for (int i = 0; i < mySize; ++i)
  {
     cout  << str3[i] << " " ;
  }
  */
  cout << "end of task D" << endl;
  cin.get();
}

void
taskE()
{
  std::cout << "task E" << std::endl;
  /*
  myLList list;
  // Append some values to the list.
  cout << "Appending to the list" << endl;
  Employee employee1{"Lisa", "Able", 4500};
  list.appendNode(employee1);
  Employee employee2{"Mark", "Cork", 4000};
  list.appendNode(employee2);
  Employee employee3{"Yoo", "Hoo", 720};
  list.appendNode(employee3);
  Employee employee4{"Boo", "Hoo", 16060};
  list.appendNode(employee4);
  list.appendNode("Sally", "Sea", 22250);
  list.appendNode("Zippy", "Zip", 150);
  list.displayList();

  cout << endl << "Now inserting into the list" << endl;
  Employee employee5{"Chuck", "Ster", 5050};
  list.insertNode(employee5);
  list.insertNode("Estoy", "Rico", 75000);
  list.displayList();

  cout << endl << "Now the reduction in force :( " << endl;
  list.deleteNode("Zip");  // OH NO!
  list.deleteNode("Zippy");
  list.displayList();
  */
  cout << "end of task E" << endl;
  cin.get();
}

// This code hereafter would normally go into a dot cpp file
//
// APPLICATION HERE
//
// PLACE CODE HERE FOR TASK A
// *************************************************
// TASK A CODE
// the ostream overload is provided


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
    std::cout << stringVar << std::endl;
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

  std::cout << "copied: " <<  stringVar << std::endl;
}

// this constructor is for initializing only PART of a string, based on given size
// remember, strings must be null terminated
myString::myString(const char * cPointer, size_t size)
{
  strLength = size;

  stringVar = new char[strLength + 1];

  for(int i = 0; i < strLength; i++)
  {
    *(stringVar + i) = *(cPointer + i);
  }

  // add null terminator
  stringVar += '\0';

  std::cout << "Partial init: " << stringVar << std::endl;

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

  std::cout << "Equals assignement operator used (literal): " << this->stringVar << std::endl;

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

  std::cout << "Equals assignement operator used (object): " << this->stringVar << std::endl;
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

  std::cout << "Plus Equals assignement operator used (object): " << this->stringVar << std::endl;
  

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
char* substr(std::size_t, std::size_t) const; //makes a string out of an existing string
    //Pre: accepts a integer for the index to start at and charAmount for the amount of characters
    //Post: returns a char pointer for the new substring

      // A member function that creates a substring comprising all of the
  // characters starting at an index i and containing n characters. The
  // index i shall be a valid position in the string. You must assert
  // this condition. If n is larger than the number of characters past i
  // then all characters after i are copied to the the output.
  // Hint: use your bounded C-string constructor.
  //
  // This function shall not modify its object.
  {
    myString const s1 = "abcdef";
    myString s2 = s1.substr(0, 3);
    myString s3 = s1.substr(3, 3);
    assert (s2 == "abc");
    assert (s3 == "def");
  }

    const bool operator==(const myString &) const; //overload for ==
    const bool operator!=(const myString &) const; //overload for !=
*/

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
/*
std::ostream& operator<<(std::ostream& input, myString const& rhs)
{
    input << rhs.stringVar;
    return input;
}
*/
// PLACE CODE HERE FOR TASK B
// *************************************************
// TASK B CODE

// PLACE CODE HERE FOR TASK C
// *************************************************
// TASK C CODE

// PLACE CODE HERE FOR TASK D
// *************************************************
// TASK D CODE

// PLACE CODE HERE FOR TASK E
// *************************************************
// TASK E CODE
// Employee class methods
// set first name
/*
void Employee::setFirstName(const std::string &name)
{
  firstName = name; // no validation needed
}
// return first name
std::string Employee::getFirstName()
{
  return firstName;
}
// set last name
void Employee::setLastName(const std::string &name)
{
  lastName = name; // no validation needed
}
// return last name
std::string Employee::getLastName()
{
  return lastName;
}
// set monthly salary; if not positive, set to 0
void Employee::setMonthlySalary(int salary)
{
  if (salary >= 0)
  { // if salary is valid
     monthlySalary = salary; // set monthlySalary to salary
  }
  if (salary < 0)
  { // if salary is negative
     monthlySalary = 0; // set monthlySalary to 0
  }
}
// return monthly salary
int Employee::getMonthlySalary()
{
  return monthlySalary;
}
// myLList code should follow here
*/
