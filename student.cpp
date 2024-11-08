/*********************************************************************
File name: student.cpp
Author: Samrakshan Rijal(oou11)
Date: Oct 18, 2024

Purpose:
    Implementation of the Student class for a basic class registration system.
Command Parameters:
    -
Input:
    -
Results:
    -
Notes:
    -
*********************************************************************/

#include "program3.h"

/*********************************************************************
Class Name: Student
Purpose:
    Default constructor initializes a Student with default values.
Notes:
    ID is set to "A00000000" and name is set to "Test Student".
*********************************************************************/
Student::Student() {
    szStudentID = "A00000000";
    szStudentName = "Test Student";
}

/*********************************************************************
Class Name: Student
Purpose:
    Parameterized constructor initializes a Student with given ID and name.
Notes:
    -
*********************************************************************/
Student::Student(string id, string name) {
    szStudentID = id;
    szStudentName = name;
}

/*********************************************************************
Class Name: Student
Purpose:
    Copy constructor initializes a Student by copying another Student.
Notes:
    -
*********************************************************************/
Student::Student(const Student& other) {
    szStudentID = other.szStudentID;
    szStudentName = other.szStudentName;
}

/*********************************************************************
Class Name: Student
Purpose:
    Destructor for the Student class.
Notes:
    No dynamic memory is currently allocated, but included for future expansion.
*********************************************************************/
Student::~Student() {
    // Nothing to do here as there is no dynamic memory allocated.
}

/*********************************************************************
Function Name: getStudentInfo
Purpose:
    Returns a formatted string containing student ID and name.
Notes:
    The format is "ID : Name".
*********************************************************************/
string Student::getStudentInfo() {
    return szStudentID + ": " + szStudentName;
}
