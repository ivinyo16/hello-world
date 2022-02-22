#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdint.h>

// convert binary to decimal



void convert(uint32_t n, char * decimal);

void convert(uint32_t n, char * decimal)
{
    int dec = 0, i = 0, rem;

    if( decimal == NULL )
    {
        decimal = (char *) malloc(64);
        printf("allocated\n");
    }

    while (n!=0) 
    {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }

    printf("dec: %u \n", UINT32_MAX);
    // snprintf(decimal, sizeof(dec), "%d", dec);
    sprintf(decimal, "%d", dec);
    printf("char %s\n", decimal);
    printf("sizeof(decimal) %lu\n", sizeof(decimal));
}



int main() 
{
    uint32_t n;
    // char * decimal = NULL;
    char decimal[64];
    printf("Enter a binary number: ");
    scanf("%u", &n);
    convert(n, decimal);
    printf("%u in binary = %s in decimal\n", n, decimal);
    return 0;
}

