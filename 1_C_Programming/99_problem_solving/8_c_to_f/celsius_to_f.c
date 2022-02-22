#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 void convertCtoF(int32_t celcius) 
{
    int32_t fahrenheit, modulo, decimal_point;
    // fahrenheit = ((celcius * 9)/5) + 32;
    fahrenheit = ((celcius * 9)/5) + 32;
    modulo = ((celcius * 9)%5);
    if( modulo == 1 )
    {
        decimal_point = 2;
    }
    else if ( modulo == 2 )
    {
        decimal_point = 4;
    }
    else if ( modulo == 3 )
    {
        decimal_point = 6;
    }
    else if ( modulo == 4 )
    {
        decimal_point = 8;
    }
    else if ( modulo == 0 )
    {
        decimal_point = 0;
    }
    printf("Fahrenheit %d.%d\n", fahrenheit, decimal_point);
}



int main(int argc, char* argv[])
{

    convertCtoF(34);

    return 0;
}
