/**
 * @file power_of_three.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given an integer n, return true if it is a power of three. Otherwise, return false.
 * 
 * An integer n is a power of three, if there exists an integer x such that n == 3x.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: n = 27
 * Output: true
 * Example 2:
 * 
 * Input: n = 0
 * Output: false
 * Example 3:
 * 
 * Input: n = 9
 * Output: true
 *  
 * 
 * Constraints:
 * 
 * -231 <= n <= 231 - 1
 * 
 * @version 0.1
 * @date 2022-08-24
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

bool isPowerOfThree(int n)
{
    //0. rule out negative numbers
    if( n <= 0 )
    {
        return false;
    }

    while(n > 1)
    {
        if((n % 3))
        {
            return false;
        }
        n /= 3;
    }

    return true;


}

int main(int argc, char* argv[])
{
    int n  = 1162261467;
    printf("is %d power of three: %s\n", n, isPowerOfThree(n) ? "true" : "false");
    

    return 0;
}
