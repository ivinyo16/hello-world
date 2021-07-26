#include <iostream>
#include "GradeBook.hpp"
using namespace std;

#if SEPERATE_INTERFACE
GradeBook::GradeBook(string name)
{
    setCourseName(name);
}

void GradeBook::setCourseName(string name)
{
    if(name.length() <= 25)
    {
        courseName = name;
    }
    else
    {
        courseName = name.substr(0,25);
        cout << "Exceeds 25 characters, Limiting course name to " << courseName << endl;
    }
}

string GradeBook::getCourseName()
{
    return courseName;
}

void GradeBook::displayMessage()
{
    cout << "Welcome to the gradebook of course " << courseName << endl;
}
#endif