/*********************************************************************
File name: course.cpp  
Author: Samrakshan Rijal (oou11)  
Date: Oct 18, 2024  

Purpose:  
    This file implements the Course class, representing a course in a basic 
    class registration system. It manages student enrollments, course capacity, 
    and provides methods to display course information.  

Command Parameters:  
    None  

Input:  
    None  

Results:  
    - Manages student enrollments within the course.
    - Provides information about the course and its students.
    - Allows for dynamic capacity management.  

Notes:  
    - The course uses dynamic memory to store enrolled students.  
    - Proper memory management is ensured with a destructor and copy assignment.
*********************************************************************/
#include "program3.h"

/*********************************************************************
Class Name: Course  
Purpose:  
    Default constructor initializes a Course object with test values.  
Notes:  
    - The course ID is set to "XXX0000" and the course name to "Test Course".  
    - The maximum enrollment is set to 10 students.
*********************************************************************/
Course::Course() {
    szCourseID = "XXX0000";
    szCourseName = "Test Course";
    iMaxStudents = 10;
    studentEnrolled = new Student[iMaxStudents];
    iNumEnrolled = 0;
}

/*********************************************************************
Class Name: Course  
Purpose:  
    Parameterized constructor initializes a Course object with a given ID, 
    name, and maximum capacity.  
Parameters:  
    I string id - Course ID.  
    I string name - Course name.  
    I int capacity - Maximum number of students that can enroll.  
Notes:  
    - Ensures flexibility in creating courses with specific details.
*********************************************************************/
Course::Course(string id, string name, int capacity) {
    szCourseID = id;
    szCourseName = name;
    iMaxStudents = capacity;
    studentEnrolled = new Student[iMaxStudents];
    iNumEnrolled = 0;
}

/*********************************************************************
Class Name: Course  
Purpose:  
    Copy constructor creates a new Course object by copying an existing one.  
Parameters:  
    I const Course& other - Reference to an existing Course object.  
Notes:  
    - Ensures deep copying of the dynamically allocated student array.
*********************************************************************/
Course::Course(const Course& other) {
    szCourseID = other.szCourseID;
    szCourseName = other.szCourseName;
    iMaxStudents = other.iMaxStudents;
    iNumEnrolled = other.iNumEnrolled;
    studentEnrolled = new Student[iMaxStudents];
    for (int i = 0; i < iNumEnrolled; ++i) {
        studentEnrolled[i] = other.studentEnrolled[i];
    }
}

/*********************************************************************
Function Name: operator=  
Purpose:  
    Assignment operator overload to correctly handle deep copying and memory 
    management when assigning one Course object to another.  
Parameters:  
    I const Course& other - Reference to the Course object being assigned.  
Return Value:  
    Course& - Reference to the modified Course object.  
Notes:  
    - Ensures proper deletion of old data and copying of new data.
*********************************************************************/
Course& Course::operator=(const Course& other) {
    if (this != &other) {
        delete[] studentEnrolled;
        szCourseID = other.szCourseID;
        szCourseName = other.szCourseName;
        iMaxStudents = other.iMaxStudents;
        iNumEnrolled = other.iNumEnrolled;
        studentEnrolled = new Student[iMaxStudents];
        for (int i = 0; i < iNumEnrolled; ++i) {
            studentEnrolled[i] = other.studentEnrolled[i];
        }
    }
    return *this;
}

/*********************************************************************
Class Name: Course  
Purpose:  
    Destructor for the Course class. Ensures that dynamically allocated memory 
    for student enrollment is released.  
Notes:  
    - Prevents memory leaks by deleting the allocated student array.
*********************************************************************/
Course::~Course() {
    delete[] studentEnrolled;
}

/*********************************************************************
Function Name: getCourseInfo  
Purpose:  
    Returns a formatted string with the course ID, name, capacity, and the 
    number of enrolled students.  
Parameters:  
    None  
Return Value:  
    string - A formatted string with course information.  
Notes:  
    - Provides a quick overview of the course details.
*********************************************************************/
string Course::getCourseInfo() {
    return "Students enrolled in "+szCourseID + ": " + szCourseName + "\nCapacity: " + to_string(iMaxStudents) + "\nEnrollment: " + to_string(iNumEnrolled);
}

/*********************************************************************
Function Name: enrollStudent  
Purpose:  
    Adds a new student to the course if there is remaining capacity.  
Parameters:  
    I const Student& newStudent - The student to be enrolled.  
Return Value:  
    bool - True if enrollment is successful, false if the course is full.  
Notes:  
    - Prints a warning message if the course has reached maximum capacity.
*********************************************************************/
bool Course::enrollStudent(const Student& newStudent) {
    if (iNumEnrolled >= iMaxStudents) {
        cout << "Max capacity reached. Please increase the course capacity before adding more students." << endl;
        return false;
    }
    studentEnrolled[iNumEnrolled++] = newStudent;
    return true;
}

/*********************************************************************
Function Name: displayStudents  
Purpose:  
    Displays information about the course and lists all enrolled students.  
Parameters:  
    None  
Return Value:  
    None  
Notes:  
    - Prints the course details followed by the list of students.
*********************************************************************/
void Course::displayStudents() {
    cout << getCourseInfo() << endl;
    for (int i = 0; i < iNumEnrolled; ++i) {
        cout << studentEnrolled[i].getStudentInfo() << endl;
    }
    cout << szBreakMessage;
}

/*********************************************************************
Function Name: increaseMaxEnrollment  
Purpose:  
    Increases the maximum enrollment capacity for the course and reallocates 
    the student array accordingly.  
Parameters:  
    I int additionalCapacity - The additional number of students allowed.  
Return Value:  
    None  
Notes:  
    - Ensures all existing student data is preserved during reallocation.
*********************************************************************/
void Course::increaseMaxEnrollment(int additionalCapacity) {
    int newCapacity = iMaxStudents + additionalCapacity;
    Student* newEnrolled = new Student[newCapacity];
    for (int i = 0; i < iNumEnrolled; ++i) {
        newEnrolled[i] = studentEnrolled[i];
    }
    delete[] studentEnrolled;
    studentEnrolled = newEnrolled;
    iMaxStudents = newCapacity;
}