
#include "student.h"
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//constructor for Student class, sets to default. Empty string and 0//
Student::Student()
{
    this -> studentID = " ";
    this -> firstName =" ";
    this -> lastName =" ";
    this -> emailAddress =" ";
    this -> age =0;
    for(int i = 0; i < daysArraySize; i++)
        this -> numOfDays[i] =0;
    this ->degree = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numOfdays[], DegreeProgram degree )
{
    //setting parameters to the field.
    
    this -> studentID = studentID;
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> emailAddress = emailAddress;
    this -> age = age;
    for(int i =0; i < daysArraySize; i++)
        this -> numOfDays[i] = numOfdays[i];
    this -> degree = degree;
}

//destructor does nothing
Student::~Student(){}

//declaring the return value for each function accessor
string Student::getID(){
    return this -> studentID;
};
string Student::getFirstName(){
    return this -> firstName;
};
string Student::getLastName(){
    return this -> lastName;
};
string Student::getEmail(){
    return this -> emailAddress;
};
int Student::getAge(){
    return this -> age;
};
//array is a pointer, and don't return individually, but all together//
int* Student::getDays(){
    return this -> numOfDays;
};
DegreeProgram Student::getDegree(){
    return this -> degree;
};


//parameter to field for all setters//

void Student::setID(string iD){
    this -> studentID = iD;
};
void Student::setFirstName(string firstName){
    this -> firstName = firstName;
};
void Student::setLastName(string lastName){
    this -> lastName = lastName;
};
void Student::setEmail(string email){
    this -> emailAddress = email;
};
void Student::setAge(int age){
    this -> age = age;
};
void Student::setDays(int numOfDays[]){
    //go through individually
    for(int i = 0; i < daysArraySize; i++)
        this -> numOfDays[i] = numOfDays[i];
};
void Student::setDegree(DegreeProgram dProgram){
    this -> degree = dProgram;
};

//prints the head of the table.
void Student::printHeader(){
    
    cout << "|Student ID|First Name   |Last Name      |Email       |Age     |Days in Course    |Degree in Program | "<< endl;
};

//prints student data//
void Student::print()
{
    //using tab to separate output
    cout<< this -> getID() << '\t';
    cout <<"First Name: "<< this -> getFirstName() << '\t';
    cout << "Last Name: "<<this -> getLastName() << '\t';
    cout << "Email: "<<this -> getEmail() << '\t';
    cout << "Age: "<<this -> getAge() << '\t';
    //no tab, because in the same block, separated by comma
    cout << "Days in Course: "<<this -> getDays()[0] << ", ";
    cout << this -> getDays() [1]<< ", ";
    cout << this -> getDays()[2] << '\t';
    //change enum to string
    cout << "Degree: "<< degreeProgramStrings[this -> getDegree()] << endl;
    
};
