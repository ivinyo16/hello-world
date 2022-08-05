/**
 * @file mirror_reflection.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.
 * 
 * The square room has walls of length p and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.
 * 
 * Given the two integers p and q, return the number of the receptor that the ray meets first.
 * 
 * The test cases are guaranteed so that the ray will meet a receptor eventually.
 * 
 * @version 0.1
 * @date 2022-08-04
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
#include <math.h>

// #define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

int gcd(int p, int q)
{
    // DEBUG_PRINT("get gcd %d %d\n", p,q);
    if( q == 0)
    {
        
        return p;
    }
    return gcd(q, p % q);
}

int mirrorReflection(int p, int q)
{
    if(q == 0)
    {
        return 0;
    }
    DEBUG_PRINT("gcd %d\n", gcd(p,q));
    int gcd_value = gcd(p,q);
    p /= gcd_value;
    q /= gcd_value;

    if( q % 2 == 0)
    {
        return 0;
    }

    if( p % 2 == 0)
    {
        return 2;
    }
    return 1;

    DEBUG_PRINT("values %d and %d\n", p, q);

    return 1;

}

/**
 * 
 * 2            1
 * -------------
 * |           |
 * |           |
 * |           |
 * |           |q
 * |-----------|
 *      p       0
 * 
 */
int main(int argc, char* argv[])
{
    int p = 3; //size of side of square
    int q = 1; //size from 0 to point of first intersection

    printf("p = %d, q = %d ; receptor %d\n", p, q, mirrorReflection(p, q));


    return 0;
}
