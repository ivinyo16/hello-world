#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long int multiplyNumbers(int n);

long int multiplyNumbers(int n) 
{
    if (n>=1)
        return n*multiplyNumbers(n-1);
    else
        return 1;
}

int main() 
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    printf("Factorial of %d = %ld\n", n, multiplyNumbers(n));
    return 0;
}


