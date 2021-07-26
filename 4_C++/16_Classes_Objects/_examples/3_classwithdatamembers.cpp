// // Fig. 16.3: fig16_03.cpp
// 2 // Define class GradeBook with a member function that takes a parameter;
// 3 // Create a GradeBook object and call its displayMessage function.

#include <iostream>
using namespace std;

class GradeBook
{
    public:
        void setCourseName(string name)
        {
            courseName = name;
        }

        string getCourseName()
        {
            return courseName;
        }

        void displayMessage()
        {
            cout << "Welcome to the gradebook of course " << courseName << endl;
        }
    private:
        string courseName;
};

int main()
{
    GradeBook my_gradebook;
    string course;

    cout << "initial value of coursename " << my_gradebook.getCourseName() << endl;

    cout << "enter course: ";
    // cin >> course; //until whitespace detected
    getline(cin, course);
    my_gradebook.setCourseName(course);

    my_gradebook.displayMessage();
}