#ifndef student_h
#define student_h

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student{
    
public:
    const static int daysArraySize = 3; // array is always three

//private because no one can touch it//
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numOfDays[daysArraySize];
    DegreeProgram degree; //from enum DegreeProgram in file//
    
public:
    Student(); //constructor- sets to default values//
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numOfdays[], DegreeProgram degree);
    ~Student(); //destructor//
    
    //accessors. will write code in student.cpp//
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegree();
    
    //setters will write code in student.cpp//
    void setID(string iD);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int numOfDays[]);
    void setDegree(DegreeProgram dProgram);
    
    //prints header to screen//
    static void printHeader();
    
    //prints student data//
     void print();
    
    
};
#endif /* student_hpp */
