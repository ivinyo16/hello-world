/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

int getSumOfMultiples(int first_number, int second_number, int limit);

int gcd(int a, int b)
{
    while ( b != 0 )
    {
        int temp = b; 
        b = a % b; 
        a = temp; 
    }
    return a;
}

int lcm(int a, int b)
{
    return ( a / gcd(a,b) ) * b;
}



// k = number ,  n = limit
//sum = k * ( (m*(m+1)) / 2 )
//where m = (n-1) / k
int sumOfMultiples(int k, int n)
{
    int m = (n-1)/k;
    return ( k * ( (m*(m+1)) / 2 ) );
}

#if 1
//o(1)
int getSumOfMultiples(int first_number, int second_number, int limit) 
{
    int first_sum = sumOfMultiples(first_number, limit);
    int second_sum = sumOfMultiples(second_number, limit);
    int lcm_sum = sumOfMultiples(lcm(first_number, second_number),  limit);

    //we subtract the sum of lcm
    return (first_sum + second_sum - lcm_sum);
}
#else
// O(n)
int getSumOfMultiples(int first_number, int second_number, int limit) 
{
    int ctr;
    int sum= 0 ;

    for ( ctr = 0 ; ctr < limit ; ctr++ )
    {
        //check first_number
        if( ctr % first_number == 0 || ctr % second_number == 0 )
        {
            sum += ctr;
        }
    }

    return sum;
}
#endif


int main(int argc, char* argv[])
{
    int limit = 1000;
    int first_number = 3;
    int second_number = 5;
    int answer = 0;

    answer = getSumOfMultiples(first_number, second_number, limit);
    DEBUG_PRINT("answer is %d\n", answer);

    return 0;
}
