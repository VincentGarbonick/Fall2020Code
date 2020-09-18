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

//Global constant for array size
const int gSIZE = 10;

// *************************************************
// PLACE ALL OF THIS PROGRAM'S prototypes and Declarations here
//
// This code would normally go into a dot hpp file
//
// SPECIFICATION HERE
//
// PLACE CODE HERE FOR TASK A
// *************************************************
std::unique_ptr<char[]> deleteRepeats(char*, short int *);
bool checkIllegal(char, std::vector<char>);

// PLACE CODE HERE FOR TASK B
// *************************************************
struct StudentInfo
{
    std::string name;
    char * pGradeArray; 
};

void gradeIt(char *, std::string);
void printIt(StudentInfo *);

// PLACE CODE HERE FOR TASK C
// *************************************************
void (* callIt(std::string))();

// prototypes for callback functions 
void yellow();
void red();
void purple();
void blue();
void white();
void green();

// PLACE CODE HERE FOR TASK D
// *************************************************
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
        float getCost();

        void setName(std::string);
        void setType(std::string);
        void setCost(float);

        // constructor declarations 
        Games();
        Games(std::string);
        Games(float);
        // Games(std::string, float);
        Games(float, std::string);
        Games(std::string, float, std::string);        
};

// PLACE CODE HERE FOR TASK E
// *************************************************
class TaxPayer 
{
    private: 
        float taxRate;
        float income; 
        float taxes;

    public:
        // prototypes for mutators
        float getTaxRate();
        float getIncome();
        float getTaxes();
        
        void  setTaxRate(float);
        void  setIncome(float);
        void  setTaxes(float);
};

void taxTaker(TaxPayer * citizen);
void taxPrint(TaxPayer * citizen);
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

    //int variable to hold number of corresponding elements
    short int repeaters = 0;
    short int * pRepeaters = &repeaters;

    //test array of chars
    char originalArray[gSIZE];
    originalArray [0] = 'a';
    originalArray [1] = 'b';
    originalArray [2] = 'b';
    originalArray [3] = 'c';
    originalArray [4] = 'a';
    originalArray [5] = 'c';
    originalArray [6] = 'a';
    originalArray [7] = 'c';
    originalArray [8] = 'b';
    originalArray [9] = 'a';
    //deleteRepeats function call, and stores returned pointer in noRepeats

    std::unique_ptr<char[]> noRepeats = deleteRepeats(originalArray, pRepeaters);
    std::cout << "The new array is: " << std::endl;
    for (int i = 0; i < gSIZE - repeaters; ++i)
    {
        std::cout << noRepeats[i] << " ";
    }

    std::cout << ", and there were " << repeaters << " repeats.";

  cout << "end of task A" << endl;
  cin.get();
}

void
taskB()
{
	// allocate first student data and fill in student data
	char student1Grades[] = {'A', 'B', 'A', 'C', 'B', 'C', 'A', 'A', 'A', 'B'};
	std::string studentName = "John";
	gradeIt(student1Grades, studentName);

	// allocate second student data and fill in student data
	char student2Grades[] = {'B', 'B', 'A', 'A', 'C', 'A', 'A', 'B', 'A', 'B'};
	studentName = "Susan";
	gradeIt(student2Grades, studentName);

	// allocate third student data and fill in student data
	char student3Grades[] = {'B', 'C', 'B', 'A', 'A', 'A', 'A', 'B', 'B', 'B'};
	studentName = "Alice";
	gradeIt(student3Grades, studentName);

  cout << "end of task B" << endl;
  cin.get();
}

void
taskC()
{
  std::string myStrings[6] = {"Colonel Mustard", "Miss Scarlet", "Professor Plum",
                   "Mrs. Peacock" , "Mrs. White" , "Rev Green" };

  for (int i = 0; i < 6; ++i)
  {
    callIt(myStrings[i]);
  }
  cout << "end of task C" << endl;
  cin.get();
}

void
taskD()
{
  std::string gameName[] = {"Puzzled Penny", "Reality", "Adventure Aardvark"}; //List of Game Names
  std::string gameType[] = {"Puzzle", "Simulation", "Adventure"}; //List of Game Types
  float gamePrice[] = {0, 50, 75}; //List of Game Prices. Inputted zero to show change to 100
  float MODIFIER = 1.1; // TO increase Prices by 10%, multiply values by this

  //Creation and Initialization of 3 Game objects
  Games Game_1(gameName[0], gamePrice[0], gameType[0]);
  Games Game_2(gameName[1], gamePrice[1], gameType[1]);
  Games Game_3(gameName[2], gamePrice[2], gameType[2]);
  Games Game_4(200, "Intrigue");
  Games Game_5(150);
  Games Game_6;

  //Outputting game data before multiplying the price by the modifier
  cout << "Game Name: " << Game_1.getName() << endl << "Game Type: " << Game_1.getType() << endl << "Game Cost: " << Game_1.getCost() << endl << endl;
  cout << "Game Name: " << Game_2.getName() << endl << "Game Type: " << Game_2.getType() << endl << "Game Cost: " << Game_2.getCost() << endl << endl;
  cout << "Game Name: " << Game_3.getName() << endl << "Game Type: " << Game_3.getType() << endl << "Game Cost: " << Game_3.getCost() << endl << endl;
  cout << "Game Name: " << Game_4.getName() << endl << "Game Type: " << Game_4.getType() << endl << "Game Cost: " << Game_4.getCost() << endl << endl;
  cout << "Game Name: " << Game_5.getName() << endl << "Game Type: " << Game_5.getType() << endl << "Game Cost: " << Game_5.getCost() << endl << endl;
  cout << "Game Name: " << Game_6.getName() << endl << "Game Type: " << Game_6.getType() << endl << "Game Cost: " << Game_6.getCost() << endl << endl;

  //Modifying the price and then outputting updated game data
  cout << "--------------------Games with 10% mark-up below:---------------------------" << endl;
  cout << "Previous costs: " << std::endl;

  std::cout << Game_1.getCost() << std::endl;
  std::cout << Game_2.getCost() << std::endl;
  std::cout << Game_3.getCost() << std::endl;
  std::cout << Game_4.getCost() << std::endl;
  std::cout << Game_5.getCost() << std::endl;
  std::cout << Game_6.getCost() << std::endl;
  
  Game_1.setCost(Game_1.getCost() * MODIFIER);
  Game_2.setCost(Game_2.getCost() * MODIFIER);
  Game_3.setCost(Game_3.getCost() * MODIFIER);
  Game_4.setCost(Game_4.getCost() * MODIFIER);
  Game_5.setCost(Game_5.getCost() * MODIFIER);
  Game_6.setCost(Game_6.getCost() * MODIFIER);

  cout << "New costs: " << std::endl;

  std::cout << Game_1.getCost() << std::endl;
  std::cout << Game_2.getCost() << std::endl;
  std::cout << Game_3.getCost() << std::endl;
  std::cout << Game_4.getCost() << std::endl;
  std::cout << Game_5.getCost() << std::endl;
  std::cout << Game_6.getCost() << std::endl;
  cout << "end of task D" << endl;
  cin.get();
}

void
taskE()
{

  TaxPayer *citizens = new TaxPayer[gSIZE];
  taxTaker(citizens);
  taxPrint(citizens);

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

// deleteRepeats deletes repeats in a dynamic arrray
// precondition: dynamically array and reference to a short integer
// postcondition: unique pointer to new dynamic array and number of repeats 
 std::unique_ptr<char[]> deleteRepeats(char * pOriginalCharArray, short int * repeaters)
{


   
    int newSize = 0; // size of the new array we are going to get 
    std::vector<char> illegalChar; // where we store the chracters that already exist in the dynamic array
    char dereferencedChar;
    bool foundCharFlag;
    *repeaters = 0;

    // go through each element in the original array
    for(int i =0; i < gSIZE; i++)
    {

        foundCharFlag = checkIllegal(*pOriginalCharArray, illegalChar);

        if(foundCharFlag == true)
        {
            // do nothing and increment repeaters
            (*repeaters) = (*repeaters) + 1;
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
    //pNewCharArray = new char [illegalChar.size()];

    std::unique_ptr<char[]> pNewCharArray (new char[illegalChar.size()]); // pointer to new character array
    // std::unique_ptr<char[]> pNewCharArray (new char[gSIZE - *repeaters]); // pointer to new character array
    // copy values over from illegalchar
    for(int i = 0; i < illegalChar.size(); i++)
    {        
        *(pNewCharArray.get() + i) = illegalChar[i];
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

// PLACE CODE HERE FOR TASK B
// *************************************************
// TASK B CODE
// Makes an instance of StudentInfo using the passed arguements, then passes the object to printit
// Precondition: character array pointer, string with student name 
// Postcondition: Nothing 
void gradeIt(char * pGradeArray, std::string studentName)
{
    StudentInfo * pTempStudent = new StudentInfo; 
    
    // copy information into dynamic struct
    pTempStudent->name = studentName;
    pTempStudent->pGradeArray = new char[gSIZE];

    std::strcpy(pTempStudent->pGradeArray, pGradeArray);
    
    printIt(pTempStudent);

    // clean up dynamically allocated information
    delete pTempStudent;

    return;
}

// Prints out the information in an instance of StudentInfo
// Precondition: pointer to StudentInfo on the heap 
// Postcondition: none 
void printIt(StudentInfo * pStudentInfoPrint)
{
    std::cout << "Student Name: " << pStudentInfoPrint->name << std::endl;
    std::cout << "Student Grades: " << pStudentInfoPrint->pGradeArray << std::endl;
    return;
}


// PLACE CODE HERE FOR TASK C
// *************************************************
// TASK C CODE
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

    pCallbackPointer();

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
// PLACE CODE HERE FOR TASK D
// *************************************************
// TASK D CODE
// class definitions, normally this would go in a seperate cpp file
Games::Games()
{
  name = "No Name";
  type = "Unknown";
  price = 0.00;  
}
// overload for type and price 
Games::Games(float overloadPrice, std::string overloadType)
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

// overload for all 3 
Games::Games(std::string oName,  float oPrice, std::string oType)
{
  name = oName;
  price = oPrice;
  type = oType;
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

// getCost returns the value in the member variable price
// precondtion: no parameters
// postcondition: return the object price
float Games::getCost()
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

// setCost sets the value of the member variable price
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void Games::setCost(float sPrice)
{
    price = sPrice;
    return;
}
// PLACE CODE HERE FOR TASK E
// *************************************************
// TASK E CODE
// taxtaker randomly instantiates and populates a dynamic array of TaxPayers
// Precon: pointer to dynamic array of taxpayer
// postcon: randomply populated taxpayer objects with taxes calculated 
void taxTaker(TaxPayer * citizen)
{
    float tempIntegerValue; 
    int randomIncome;
    float randomRate; 
    
    bool foundCorrectIncome = false; 
    bool foundCorrectRate = false;

    for(int i = 0; i < gSIZE; i++)
    {
                
        do
        {
          
          randomIncome = rand()%(50000-5000 + 1) + 5000;

          if(randomIncome >= 5000 && randomIncome <= 50000)
          {
            foundCorrectIncome = true;
          }

        } while (!foundCorrectIncome);
        
        foundCorrectIncome = false;

        do
        {
          
        tempIntegerValue = ( rand()%(990-1 + 1) + 1 );        
        randomRate = tempIntegerValue/100;

          if(randomRate >= 0.01 && randomRate <= 9.9)
          {
            foundCorrectRate = true;
          }

        } while (!foundCorrectRate);

        foundCorrectRate = false;

        // std::cout << "RandIncome:" << randomIncome << std::endl;
        // std::cout << "RandRate:" << randomRate << "\n" << std::endl;
        
        // set randomly calculated values
        (citizen+i)->setIncome(randomIncome);
        (citizen+i)->setTaxRate(randomRate);
        (citizen+i)->setTaxes( ( (randomRate/100) * randomIncome ) );
    }

    return;
} 


// taxPrint: prints out the tax rate for all taxpayers in the dynamic array
// precon: pointer to dynamic array of taxpayer
// postcon: none 
void taxPrint(TaxPayer * citizen)
{

    for(int i = 0; i < gSIZE; i++)
    {
        std::cout << "Taxes for citizen " << i << ": " << (citizen + i)->getTaxes() << std::endl;
    }

    return;
}

// getTaxRate returns the value in the member variable taxRate
// precondtion: no parameters
// postcondition: return the object taxRate
float TaxPayer::getTaxRate()
{
    return taxRate;
}

// getIncome returns the value in the member variable income
// precondtion: no parameters
// postcondition: return the object income
float TaxPayer::getIncome()
{
    return income;
}

// getTaxes returns the value in the member variable taxes
// precondtion: no parameters
// postcondition: return the object taxes
float TaxPayer::getTaxes()
{
    return taxes;
}



// setTaxRate sets the value of the member variable taxRate
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void TaxPayer::setTaxRate(float sTaxRate)
{
    taxRate = sTaxRate;
    return;
}

// setIncome sets the value of the member variable income
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void TaxPayer::setIncome(float sIncome)
{
    income = sIncome;
    return;
}

// setTaxes sets the value of the member variable taxes
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void TaxPayer::setTaxes(float sTaxes)
{
    taxes = sTaxes;
    return;
}




