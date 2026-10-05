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
#include <stdatomic.h>
#include <stdint.h>

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

int16_t q15_mul(int16_t a, int16_t b);

int16_t q15_mul(int16_t a, int16_t b)
{
    int32_t product = (int32_t)a * (int32_t)b;
    int32_t result = product >> 15;

    if (result > INT16_MAX)
    {
        result = INT16_MAX;
    }
    else if (result < INT16_MIN)
    {
        result = INT16_MIN;
    }

    return (int16_t)result;
}




int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    DEBUG_PRINT("%d\n", q15_mul(16384, 16384));
    DEBUG_PRINT("%d\n", q15_mul(32767, 32767));
    DEBUG_PRINT("%d\n", q15_mul(-32768, 32767));


    return 0;
}
