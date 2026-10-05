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

enum mode {IDLE, ACTIVE, ERROR};
void set_mode(enum mode m);
uint8_t tick(); // returns LED state

static enum mode curr_mode = IDLE;
uint8_t led_state = 0;
uint8_t cnt = 0;

void set_mode(enum mode m)
{
    curr_mode = m;
    cnt = 0;
}

/* Called every 125ms */
uint8_t tick()
{
    if( curr_mode == IDLE )
    {
        led_state = 0;
    }
    else if( curr_mode == ACTIVE )
    {
        if( ++cnt >= 4 )
        {
            led_state = !led_state;
            cnt = 0;
        }
    }
    else if ( curr_mode == ERROR )
    {
        if( ++cnt >= 1)
        {
            led_state = !led_state;
            cnt = 0;
        }
    }
    else
    {
        led_state = 0;
    }
    return led_state;
}




int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;



    return 0;
}
