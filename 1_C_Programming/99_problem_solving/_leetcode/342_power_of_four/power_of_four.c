/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given an integer n, return true if it is a power of four. Otherwise, return false.
 * 
 * An integer n is a power of four, if there exists an integer x such that n == 4x.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: n = 16
 * Output: true
 * Example 2:
 * 
 * Input: n = 5
 * Output: false
 * Example 3:
 * 
 * Input: n = 1
 * Output: true
 * 
 * Techniques used:
 *  - bit manipulation
 * 
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

bool isPowerOfFour(int n)
{
    if( n <= 0 )
    {
        return false;
    }
    DEBUG_PRINT("value 0x%X\n", n);
    int value = !(n & (n - 1));
    DEBUG_PRINT("compute: 0x%X\n", value);
    long int value2 = !(n &  0xAAAAAAAA);
    DEBUG_PRINT("compute: 0x%lX\n", value2);
    if(value && value2)
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    bool answer = isPowerOfFour( 64 );
    printf("answer: %s\n", answer ? "true" : "false" );

    return 0;
}
