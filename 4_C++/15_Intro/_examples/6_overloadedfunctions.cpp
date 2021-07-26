/*
*   Showcasing overloaded functions
*   parameters need to be different, not just return type
*   view assembled code using godbolt.org
*/
#include <iostream>
using namespace std;

#define VIEW_ASSEMBLY 0

//note: tried adding default values but couldn't get to use square() without error
int square(int value)
{
    return value *= value;
}

double square(double value)
{
    return value *= value;
}

void nothing1( int a, float b, char c, int &d )
{

}
int nothing2( char a, int b, float &c, double &d )
{
    return 0;
}

int main()
{
#if !VIEW_ASSEMBLY
    int x = 4;
    double y = 2.5;

    cout << "x " << x << "square(x) " << square(x) << endl;
    cout << "y " << x << "square(y) " << square(y) << endl;
#endif
    return 0;
}