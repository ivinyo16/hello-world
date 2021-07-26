#include<iostream>

using namespace std;

class GradeBook
{
    public:
        void displayMessage()
        {
            cout << "Welcome to the gradebook" << endl;
        }
};

int main()
{
    GradeBook my_gradebook;
    my_gradebook.displayMessage();
}