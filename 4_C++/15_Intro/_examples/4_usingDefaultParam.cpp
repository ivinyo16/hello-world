#include <iostream>
using namespace std;


#define  USE_OTHER_WAY 1 //0 shows error, only in prototypes or function headers
//function proto with defaults
#if USE_OTHER_WAY
// int boxVolume(int length = 1, int width = 1, int height = 1);
int boxVolume(int length = 1, int width = 1, int height = 1);
#else
int boxVolume(int length, int width, int height);
#endif

int main()
{
    cout << "without arguments: " << boxVolume() << endl;

    cout << "with some arguments: " << boxVolume(1,2) <<endl;


    cout << "with all arguments: " << boxVolume(1,2,4) <<endl;
}

#if USE_OTHER_WAY
int boxVolume(int length, int width , int height)
#else
int boxVolume(int length = 2, int width = 2, int height = 2)
#endif
{
    return length*width*height;
}