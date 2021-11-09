#include<string>
using namespace std;
#include "degree.h"
#include "student.h"
#ifndef roster_h
#define roster_h

class Roster {
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    

    public :
    
    //goes through a set of comma delimited strings and gathers data from student table//
    void parse(string longString);
    Student* classRosterArray[numStudents];
    
    //All student data is put into add that sets the instance variables from stdent table and updates roster//
    void add(string StudentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeprogram);
    
    //Question 3b. Removes students from roster, if student doesn't exist, error message- code in roster.cpp//
    void remove(string studentID);
    //Question 3c. prints a complete tab-separated list of all info-code in roster.cpp//
    void printAll();
    //Question 3d. prints students average number of days in a course by studentID-code in roster.cpp//
    void printAverageDaysInCourse(string StudentID);
    //question 3e. verifies student email. Should include @, ./ no space.-code in roster.cpp//
    void printInvalidEmails();
    //Question 3f. prints out student info for a degree program by enum.-code in roster.cpp//
    void printByDegreeProgram(DegreeProgram degreeprogram);
    //always include
    ~Roster(); 
    

    

    
    
    
};
#endif /* roster_h */
