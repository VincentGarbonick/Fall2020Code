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

//Global constant for array size
const int SIZE = 10;

// *************************************************
// PLACE ALL OF THIS PROGRAM'S prototypes and Declarations here
//
// This code would normally go into a dot hpp file
//
// SPECIFICATION HERE
//
// PLACE CODE HERE FOR TASK A
// *************************************************

// PLACE CODE HERE FOR TASK B
// *************************************************

// PLACE CODE HERE FOR TASK C
// *************************************************

// PLACE CODE HERE FOR TASK D
// *************************************************

// PLACE CODE HERE FOR TASK E
// *************************************************

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
    //test array of chars
    char originalArray[SIZE];
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
    std::unique_ptr<char[]> noRepeats = deleteRepeats(originalArray, repeaters);
    std::cout << "The new array is: " << std::endl;
    for (int i = 0; i < SIZE - repeaters; ++i)
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
  Game_1.setCost(Game_1.getCost() * MODIFIER);
  Game_2.setCost(Game_2.getCost() * MODIFIER);
  Game_3.setCost(Game_3.getCost() * MODIFIER);
  Game_4.setCost(Game_4.getCost() * MODIFIER);
  Game_5.setCost(Game_5.getCost() * MODIFIER);
  Game_6.setCost(Game_6.getCost() * MODIFIER);

  cout << "end of task D" << endl;
  cin.get();
}

void
taskE()
{

  TaxPayer *citizens = new TaxPayer[SIZE];
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





