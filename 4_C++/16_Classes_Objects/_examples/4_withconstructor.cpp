// 2 // Instantiating multiple objects of the GradeBook class and using
// 3 // the GradeBook constructor to specify the course name
// 4 // when each GradeBook object is created.
#include <iostream>
using namespace std;

class GradeBook
{
    public:

        GradeBook(string name)
        {
            setCourseName(name);
        }

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
    GradeBook my_gradebook("sex education");
    GradeBook gradebook1("Science");
    GradeBook gradebook2("History and Geography");
    string course;

    cout << "gradebook1 course " << gradebook1.getCourseName() << endl;
    cout << "gradebook2 course " << gradebook2.getCourseName() << endl;

    cout << "initial value of coursename " << my_gradebook.getCourseName() << endl;

    cout << "enter course: ";
    // cin >> course; //until whitespace detected
    getline(cin, course);
    my_gradebook.setCourseName(course);

    my_gradebook.displayMessage();
}