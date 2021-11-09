
#include "roster.h"
#include "student.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//goes through a set of comma delimited strings and gathers data from student table//
void Roster::parse(string studentdata)
{
    //starts at right side, finds the comma and extracts the substring for student ID//
    int rightSide = studentdata.find(",");
    string studentID = studentdata.substr(0, rightSide);
    
    //moves past the comma, stops at next comma for first name
    int leftSide = rightSide +1;
    rightSide = studentdata.find(",", leftSide);
    string fname = studentdata.substr(leftSide, rightSide - leftSide);
    
    //continue throughout the string- last name//
    leftSide = rightSide + 1;
    rightSide = studentdata.find(",", leftSide);
    string lname = studentdata.substr(leftSide, rightSide - leftSide);
    
    //continue throughout the string- email//
    leftSide = rightSide + 1;
    rightSide = studentdata.find(",", leftSide);
    string email = studentdata.substr(leftSide, rightSide - leftSide);
    
    //continue throughout the string- different because int -age//
    leftSide = rightSide + 1;
    rightSide = studentdata.find(",", leftSide);
    int age =stoi(studentdata.substr(leftSide, rightSide - leftSide));
    
    //continue on. different because int - numOfDays array. day1.//
    leftSide = rightSide + 1;
    rightSide = studentdata.find(",", leftSide);
    int day1 =stoi(studentdata.substr(leftSide, rightSide - leftSide));
    
    //day 2//
    leftSide = rightSide + 1;
    rightSide = studentdata.find(",", leftSide);
    int day2 =stoi(studentdata.substr(leftSide, rightSide - leftSide));
    
    //day 3//
    leftSide = rightSide + 1;
    rightSide = studentdata.find(",", leftSide);
    int day3 =stoi(studentdata.substr(leftSide, rightSide - leftSide));
    
    //program//
    leftSide = rightSide + 1;
    rightSide = studentdata.find(",", leftSide);
    string tempDegree = studentdata.substr(leftSide, rightSide - leftSide) ;
    //use tempDegree string to search for letter//
    DegreeProgram program = SECURITY; //default
    if (tempDegree.at(0) == 'N')
        program = NETWORK;
    else if(tempDegree.at(1) == 'O')
        program = SOFTWARE;
    
    add(studentID, fname, lname, email, age, day1, day2, day3, program);
};


//All student data is put into add that sets the instance variables from stdent table and updates roster//
void Roster::add(string StudentID,
         string firstName,
         string lastName,
         string emailAddress,
         int age,
         int daysInCourse1,
         int daysInCourse2,
         int daysInCourse3,
        DegreeProgram degreeprogram)
{
    //Put days back into array from constructor. //
    
    int tempDays[3] = {daysInCourse1, daysInCourse2, daysInCourse3 };
    
    //new info. last index starts at -1.
    classRosterArray[++lastIndex] = new Student(StudentID, firstName, lastName, emailAddress, age, tempDays, degreeprogram);
    
}


//Question 3b. Removes students from roster, if student doesn't exist, error//
void Roster::remove(string studentID)
{
    //declare bool to false
    bool studentFound = false;
    
    for(int i = 0; i <= Roster::lastIndex; i++)
    {
        if(classRosterArray[i]-> getID() == studentID)
        {
            studentFound = true; //studentID found
            
            if(i < numStudents - 1)
            {
                //swaps with last student
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            //make last student no longer visible, not delete, just removed from table.
            Roster::lastIndex--;
        }
    }
    if(studentFound)
    {
        cout << studentID << " was removed from roster."<<endl;
    }
    else
        cout << studentID << " not found."<<endl; 
    
}

//Question 3c. prints a complete tab-separated list of all info//
void Roster::printAll()
{
    
    for(int i = 0; i <= Roster::lastIndex; i++)
    {
        
        if (classRosterArray[i] != nullptr){
            classRosterArray[i]  -> print();
        }
    }

}
//Question 3d. prints students average number of days in a course by studentID//
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i =0; i <= lastIndex; i++){
        if(classRosterArray[i]-> getID() == studentID)
    {
        double averageNum = (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1]
                             + classRosterArray[i] -> getDays()[2])/3.0;
        cout << fixed << std::setprecision(1);
        cout << classRosterArray[i] -> getID() << " "<< classRosterArray[i] -> getLastName()<< ": "<<  averageNum << endl;
        cout<<endl;
    }
 
}
}

//question 3e. verifies student email. Should include @, ./ no space.//
void Roster::printInvalidEmails()
{
    //declare boolean false
    bool invalidEmail = false;
    
    
    for(int i =0; i <=Roster::lastIndex; i++)
    {
        //temp variables//
        string email = (classRosterArray[i] -> getEmail());
        int atSymbolIndex;
        int periodIndex;
        int spaceIndex;
        
        atSymbolIndex = email.find('@');
        periodIndex = email.find('.');
        spaceIndex = email.find(' ');
        
        if((atSymbolIndex == string::npos && periodIndex == string::npos) || spaceIndex != string::npos)
        {
            invalidEmail = true;
            cout <<classRosterArray[i]->getID() << " "  << classRosterArray[i] -> getFirstName() << " " << classRosterArray[i]-> getLastName()<< " " << email<< endl;
        }

            
        }
    if(!invalidEmail)
        cout << "All emails are valid."<<endl;
        
    }
    
    

        
    
    

//Question 3f. prints out student info for a degree program by enum//
void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
    
    for(int i =0; i <= Roster::lastIndex; i++)
    {
        if(Roster::classRosterArray[i] -> getDegree() == degreeprogram)
            classRosterArray[i] -> print();
    }
    cout << endl;
}

//always include
Roster::~Roster()
{
    cout << "Destructor called!"<<endl;
    for(int i = 0; i < numStudents; i++)
    {
        cout << "Permanetely deleting student: " << i + 1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr; 
    }
}


