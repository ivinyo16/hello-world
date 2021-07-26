//  Program to test class Time.
#include <iostream>
#include "Time.hpp"


using namespace std;

int main()
{
    Time t;

    cout << "initial value is at ";
    t.printStandard();
    cout << " or ";
    t.printUniversal();

    t.setTime(13,27,56);

    cout << "new value is at ";
    t.printStandard();
    cout << " or ";
    t.printUniversal();
}