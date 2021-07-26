/*
*   How to access global variables that share the same name with a local variable
*   Using Unary (::) operator
*/
#include <iostream>
using namespace std;

int number = 5;

int main()
{
    double number = 3.4;
    cout << "local variable: " << number << endl;
    cout << "global variable: " << ::number << endl;
    
}