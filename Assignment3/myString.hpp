

#ifndef MYSTRING_DEFINED
#define MYSTRING_DEFINED

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
    
    friend std::ostream& operator<<(std::ostream&, myString const&); //overload << operator to output stringVar
    

    
    myString& operator=(const char*); //overload assignment operator to take string literal
    myString& operator=(const myString &); //overload assignment operator to take in an object of the same type
    myString& operator+=(const myString &); //overload operator for the concatenation    
    char& operator[](const std::size_t ); //overload operator [] to return values and change values at index n
    const char& operator[](std::size_t ) const; //const version of [] overload
    
    const bool operator==(const myString &) const; //overload for ==
    const bool operator!=(const myString &) const; //overload for !=
    
    
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

#endif