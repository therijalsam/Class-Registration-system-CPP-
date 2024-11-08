                                                                **Class Registration System**

****************************************************************************************************************************************************************************************************************
**Part 1: Creating the Student Class**
Implement the Student class in a file called student.cpp with the following requirements:

**Default constructor**
           Prototype: Student();
           Should initialize the ID to "A00000000" and the name to "Test Student".
          
**Parameterized constructor**
            Prototype: Student(string id, string name);
            Should set the ID and name to the values passed as arguments, in that order.
            
**Copy constructor**
            Prototype: Student(const Student& other);
            Should copy the ID and name from another Student object into the current object.
            
**Destructor**
             Prototype: ~Student();
             Although no dynamic memory is currently allocated, ensure you include the destructor for consistency and possible future expansion.
             
**Student Info Function**
             Prototype: string getStudentInfo();
             Should return a formatted string containing the studentID and the name, separated by a colon (:).
             
 Your **student.cpp** class should include my program3.h file as it has the prototype for all of these requirements.
****************************************************************************************************************************************************************************************************************
**Part 2: Creating the Course Class** 
Implement the Courses class in a file called course.cpp with the following prototypes and details:

**Default constructor**
            Prototype: Course();
            Should initialize the ID to "XXX0000", the name to "Test Course", and the maximum enrollment to 10 students.
                  Dynamically allocate an array to hold the students.
                  
**Parameterized constructor**
            Prototype: Course(string id, string name, int capacity);
            Should set the ID, name, and maximum enrollment to the provided values, in that order.
                  Dynamically allocate an array for the students based on the passed capacity.
                  
**Copy constructor** 
            Prototype: Course(const Course& other);
            Should create a deep copy of another Course object.
                  Ensure that the dynamically allocated array for students is properly handled.
                  
**Assignment Operator**
             Prototype: Course& operator=(const Course& other);
            Should assign one Course object's data to another, handling dynamic memory for students properly.
            
**Destructor**
            Prototype: ~Course();
            Should release any dynamically allocated memory, such as the students' array.
            
**Course Info Function**
            Prototype: string getCourseInfo();
            Should return a formatted string containing:
                    CourseID and CourseName separated by a colon (:).
                    "Capacity: " followed by the course's enrollment capacity.
                    "Enrollment: " followed by the current number of enrolled students.
                    
**Enrollment Function**
            Prototype: bool enrollStudent(const Student& newStudent);
            Should add a new student to the course if the course is not at maximum capacity.
                      If the course is full, print:
                            "Max capacity reached. Please increase the course capacity before adding more students."
                      If enrollment is successful, return true. Otherwise, return false.
                      
**Display Course Students Function**
              Prototype: void displayStudents();
              Should print the course information from getCourseInfo().
                      Should then loop through the students and print their info using their getStudentInfo() function.
                      
**Increase Enrollment Function**
                Prototype: void increaseMaxEnrollment(int additionalCapacity);
                Should increase the enrollment of the course by the specified number.
                      Properly handle the reallocation of the students' array to accommodate the new capacity.

Your **course.cpp** class should include my program3.h file as it has the prototype for all of these requirements.
****************************************************************************************************************************************************************************************************************
**Part 3: Handle the File Processing** 

Create a utils.cpp file with the following prototypes and details:

**Function to process file information**

            **Prototype**: void processCourseInformation(ifstream& fileInput, Course* courseArr, Student* studentArr, int& courseCount, int& studentCount);
                  Course* and Student* are pointers to an array of courses and student respectively. You do not have to name your parameters what I did, but they do I have to be the types I specified.
            The function should perform the following steps:
                **Start** courseCount and studentCount at 0.
                **Loop** through the text file to read and process each line.
                **Read** a line from the file.
                **Determine** if the line contains course information or student information.
                **Update the corresponding array** (courses or students) with the relevant information from the file.
                        Don't forget to enroll the student in the course!
                **Update the integers** (courseCount and studentCount) to reflect how many courses and students were successfully processed.

**Assumptions:**
You may assume that the arrays for courses and students will not need to be resized during processing.
Each course's information in the text file will be separated by a line of asterisks (*) to indicate the start of a new course.
An example text file is shown below
Note: The comments will not be in the text file provided, there are just here to provide clarity.
Your utils.cpp class should include my program3.h file as it has the prototype for all of these requirements.


Code Block 8.4.2: Example Text File
                                            CS2308 Data Structures        // Course Code, Course Name
                                            7                             // Max Capacity for Course
                                            A0123456 Carol Williams       // Student ID, Student name
                                            A0123484 Liam Young           // Student ID, Student name
                                            A0123446 Sam Adams            // Student ID, Student name
                                            A0123490 Emily Chen           // Student ID, Student name
                                            *********************         // Breaker line
****************************************************************************************************************************************************************************************************************

   **How to Run the code:**
   Step.1:- Open terminal with floder repo where all these files are kept together.
   Step.2:- Type "Make". This will debug the code
   Step.3:- Type "Make run". It will run the program with '	./program3.out ./course_and_student_data.txt' file. 
   
   ****************************************************************************************************************************************************************************************************************

   **Notice:-**
   Please donot copy the code or download any files wihtout my permission.
   
   ****************************************************************************************************************************************************************************************************************
