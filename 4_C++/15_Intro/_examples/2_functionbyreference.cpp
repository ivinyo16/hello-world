// Comparing pass-by-value and pass-by-reference with references
#include <iostream>

using namespace std;


//function prototypes are required in C++
int squarebyValue(int value);
void squarebyReference(int &);

int main()
{
    int x = 2;
    int z = 4;

    cout << "x = " << x << " squarebyValue(x) = " << squarebyValue(x) << endl;
    cout << "z = " << z << endl;
    squarebyReference(z);
    cout <<"squarebyReference(x) = " << z << endl;
}

int squarebyValue(int value)
{
    return value *= value;
}

void squarebyReference( coint &referenceValue)
{
    referenceValue *= referenceValue;
}

