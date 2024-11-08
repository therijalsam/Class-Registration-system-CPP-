#include "program3.h"
#include <fstream>
#include<sstream>
#include <string>

/*********************************************************************
File name: utils.cpp
Author: <Samrakshan Rijal>(oou11)
Date: Oct 18, 2024

Purpose:
   Utility functions for processing course and student information from files.
Command Parameters:
   - ifstream& fileInput: Input file stream containing course and student information.
   - Course* coursesArr: Array to store courses information.
   - Student* studentArr: Array to store student information.
   - int& courseCount: Reference to store the number of courses processed.
   - int& studentCount: Reference to store the number of students processed.
Input:
   Reads course and student information from an input file.
Results:
   Populates course and student arrays with the relevant information.
Notes:
   Assumes that the input file is formatted correctly with each course section followed by students.
   Each course's information ends with a line of asterisks ("*********************").
*********************************************************************/

/*********************************************************************
Function Name: processCourseInformation  
Purpose:  
    Reads course and student data from the input file and stores the information 
    in provided arrays. Associates students with their corresponding courses.  

Parameters:  
    I ifstream& fileInput - Input file stream containing the course and student information.  
    O Course* coursesArr - Array to store the course objects.  
    O Student* studentArr - Array to store the student objects.  
    O int& courseCount - Reference to store the total number of courses processed.  
    O int& studentCount - Reference to store the total number of students processed.  

Return Value:  
    None  

Notes:  
    - It alternates between reading course and student information.
    - Assumes that student entries follow each course in the file.
    - The input file must contain valid data with asterisks marking the end of each course section.  
*********************************************************************/
void processCourseInformation(ifstream& fileInput, Course* coursesArr, Student* studentArr, int& courseCount, int& studentCount) {
    courseCount = 0;
    studentCount = 0;
    string line;
    bool readingCourse = true;
    while (getline(fileInput, line)) {
        if (line == "*********************") {
            readingCourse = true;
            continue;
        }
        if (readingCourse) {
            // Course information line
            stringstream ss(line);
            string id, name;
            int capacity;
            ss >> id;
            ss >> ws;
            getline(ss, name);
            fileInput >> capacity;
            fileInput.ignore();
            coursesArr[courseCount] = Course(id, name, capacity);
            courseCount++;
            readingCourse = false;
        } else {
            // Student information line
            stringstream ss(line);
            string id, name;
            ss >> id;
            getline(ss, name);
            studentArr[studentCount] = Student(id, name);
            coursesArr[courseCount - 1].enrollStudent(studentArr[studentCount]);
            studentCount++;
        }
    }
}
