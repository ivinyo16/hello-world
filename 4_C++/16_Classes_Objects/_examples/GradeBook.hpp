// 2 // Instantiating multiple objects of the GradeBook class and using
// 3 // the GradeBook constructor to specify the course name
// 4 // when each GradeBook object is created.
#include <string>
using namespace std;

#define SEPERATE_INTERFACE 1

#if SEPERATE_INTERFACE
class GradeBook
{
    public:

        GradeBook(string);
        void setCourseName(string);
        string getCourseName();
        void displayMessage();
    private:
        string courseName;
};

#else
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
#endif