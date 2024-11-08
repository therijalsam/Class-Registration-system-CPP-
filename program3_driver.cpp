#include "program3.h"

/*********************************************************************
File name: program3_driver.cpp
Author: Dr.Patrick (ueg11)
Date: 09/05/2024

Purpose:
    Driver for program 3 to simulate course registration.
Command Parameters:
    File with course and student information.
Input:
    User input
Results:
    Course simulation.
Notes:
    -
*********************************************************************/
int main(int argc, char *argv[])
{
    ifstream fileInput; 
    string szFilename;

    if(argc != 2)
    {
        cout << "Not enough arguments" << endl;
        return -1;
    }

    // Open the provided file
    fileInput.open(argv[1]);

    if(!fileInput)
    {
        cout << "File did not open properly" << endl;
        return -2;
    }

    int iMaxCourses = 20;
    int iMaxStudents = 60;

    // Dynamically allocate the arrays
    Course* coursesArr = new Course[iMaxCourses];
    Student* studentArr = new Student[iMaxStudents];

    int iCourseIndex;
    int iStudentIndex;

    // Process the information
    processCourseInformation(fileInput, coursesArr, studentArr, iCourseIndex, iStudentIndex);

    // Close the provided file
    fileInput.close();

    // Display all of the courses with current students enrolled
    for(int i = 0; i < iCourseIndex; i++)
    {
        coursesArr[i].displayStudents();
        cout << endl;
    }

    cout << szBreakMessage;

    // Create a fake student to add to all courses
    Student studentA = Student("A0349002", " Bob Marley");

    // Display all of the courses with current students enrolled
    for(int i = 0; i < iCourseIndex; i++)
    {
        coursesArr[i].enrollStudent(studentA);
        coursesArr[i].displayStudents();
        cout << endl;
    }

    cout << szBreakMessage; 

    coursesArr[0].increaseMaxEnrollment(5);

    // Display all of the courses with current students enrolled
    for(int i = 0; i < iCourseIndex; i++)
    {
        coursesArr[i].displayStudents();
        cout << endl;
    }

    cout << szBreakMessage; 

    // Delete the dynamically allocated arrays
    delete[] studentArr;
    delete[] coursesArr;

    return 0;
}