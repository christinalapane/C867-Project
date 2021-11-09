#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;



int main(){
    
    //The student data information- to parse in roster.cpp//
    const string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Christina,LaPane,clapane@wgu.edu,30,30,40,50,NETWORK"
        };
    //declare numStudents//
    const int numStudents = 5;
    
    //F2. instance of Roster//
    Roster classRoster;
    
    
    //F1. Student Information//
    cout << "Course Title: Scripting and Programming C867"<<endl;
    cout << "Programming Language: C++"<<endl;
    cout << "Student ID: 008207171"<<endl;
    cout << "Name: Christina LaPane"<<endl;
    cout << endl;
    cout << endl; 
    
    //F3. Adds each student to the roster.
    for(int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    
    //F4. Print All//
    cout << "Displaying roster: "<<endl;
    classRoster.printAll();
    cout << endl;
    
    //F4. print InvalidEmails//
    cout << "Students with invalid emails: "<<endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    //F4. Code is in roster.h print average days
        cout << "Average days in each course: " << endl;
    
    for(int i = 0; i <= numStudents; i++){
    classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    
    //F4. Printing by software degree//
    cout << "Student information from students in the Software Program: "<<endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    
    //F4. Remove "A3"//
    cout << "Removing student information with Student ID A3"<<endl;
    classRoster.remove("A3");
    cout << endl;
    
    //F4. Print all.
    cout << "Displaying updated roster: "<<endl;
    classRoster.printAll();
    cout << endl;
    
    //F4. Remove "A3" to confirm it's gone
    cout << "Confirming A3 doesn't exist: "<<endl;
    classRoster.remove("A3");
    cout << endl;
    
    
    

    
    return 0; 
}
