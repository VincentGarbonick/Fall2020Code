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

struct StudentInfo
{
    std::string name;
    char * pGradeArray; 
};

void gradeIt(char *, std::string);
void printIt(StudentInfo *);

int main(void)
{
    char * pGradeArray = new char[gSIZE];

    *  pGradeArray = 'a';
    * (pGradeArray + 1)= 'a';
    * (pGradeArray + 2)= 'n';
    * (pGradeArray + 3)= 'a';
    * (pGradeArray + 4)= 'a';
    * (pGradeArray + 5)= 'q';
    * (pGradeArray + 6)= 'a';
    * (pGradeArray + 7)= 'a';
    * (pGradeArray + 8)= 'a';
    * (pGradeArray + 9)= 'z';

    gradeIt(pGradeArray, "Grace Rose");

    return 0;
}

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
    delete [] pTempStudent->pGradeArray;
    delete [] pGradeArray;
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