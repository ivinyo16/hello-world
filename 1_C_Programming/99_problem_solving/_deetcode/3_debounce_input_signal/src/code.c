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

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

int debounce(int raw)
{
    static int state = 0;
    static int cnt = 0;
    if(raw == state)
    {
        cnt = 0;
    }
    else
    {
        if( ++cnt >= 5 )
        {
            state = raw;
            cnt = 0;
        }
    }
    return state;
}

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    DEBUG_PRINT( "output: %d\n", debounce(1));
    DEBUG_PRINT( "output: %d\n", debounce(0));
    DEBUG_PRINT( "output: %d\n", debounce(1));
    DEBUG_PRINT( "output: %d\n", debounce(1));
    DEBUG_PRINT( "output: %d\n", debounce(1));
    DEBUG_PRINT( "output: %d\n", debounce(1));
    DEBUG_PRINT( "output: %d\n", debounce(1));



    return 0;
}
