#include <iostream>
#include <iomanip>
#include "Time.hpp"
using namespace std;

Time::Time()
{
    int hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s)
{
    hour = ( h >= 0 && h < 24 ) ? h : 0;
    minute = ( m >= 0 && m < 59 ) ? m : 0;
    second = ( s >= 0 && s < 59 ) ? s : 0;
}

void Time::printUniversal()
{
    cout << setfill('0') << setw(2) << hour << ":" 
        << setw(2) << minute << ":" 
        << setw(2) << second << endl;
}

void Time::printStandard()
{
    cout << setfill('0') << setw(2) << 
        ((hour == 0 || hour == 12) ? 12 : hour % 12)  << ":" 
        << setw(2) << minute << ":" 
        << setw(2) << second << 
        (hour >= 12 ? "PM" : "AM") << endl;
}