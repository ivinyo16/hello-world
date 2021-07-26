// // Fig. 16.3: fig16_03.cpp
// 2 // Define class GradeBook with a member function that takes a parameter;
// 3 // Create a GradeBook object and call its displayMessage function.

#include <iostream>
using namespace std;

class GradeBook
{
    public:
        void displayMessage( string courseName)
        {
            cout << "Welcome to the gradebook of courseName " << courseName << endl;
        }
};

int main()
{
    GradeBook my_gradebook;
    string course;

    cout << "enter course: ";
    // cin >> course; //until whitespace detected
    getline(cin, course);
    my_gradebook.displayMessage(course);
}