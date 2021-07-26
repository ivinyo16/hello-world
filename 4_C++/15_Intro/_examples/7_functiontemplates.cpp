// All function template definitions
// begin with the template keyword (line 4) followed by a template parameter list to the
// function template enclosed in angle brackets (< and >). Every parameter in the template
// parameter list (each is referred to as a formal type parameter) is preceded by keyword
// typename or keyword class (which are synonyms). The formal type parameters are placeholders
// for fundamental types or user-defined types. These placeholders are used to specify
// the types of the function’s parameters (line 5), to specify the function’s return type (line
// 5) and to declare variables within the body of the function definition (line 7). A function
// template is defined like any other function, but uses the formal type parameters as placeholders
// for actual data types.

#include<iostream>
#include "maximum.hpp"

using namespace std;

int main ()
{
    int int1, int2, int3;
    double dob1 , dob2, dob3;
    char char1, char2, char3;

    cout << "Input three integer values: ";
    cin >> int1 >> int2 >> int3;
    cout << "maximum is " << maximum(int1, int2, int3) << endl;

    cout << "Input three double values: ";
    cin >> dob1 >> dob2 >> dob3;
    cout << "maximum is " << maximum(dob1, dob2, dob3) << endl;

    cout << "Input three char values: ";
    cin >> char1 >> char2 >> char3;
    cout << "maximum is " << maximum(char1, char2, char3) << endl;


}