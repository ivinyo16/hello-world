#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i, a = 1, count, sum = 0;


    while(a <= 1000)
    {
        count = 0;
        i = 2;
        while(i <= a/2)
        {
            if(a%i == 0)
            {
                count++;
                break;
            }
            i++;
        }
        if(count == 0 && a != 1 )
        {
            printf(" %d ", a);
            sum = sum + a;
        }
        a++; 
    }
    printf("\nSum: %d\n", sum);
    return 0;
}