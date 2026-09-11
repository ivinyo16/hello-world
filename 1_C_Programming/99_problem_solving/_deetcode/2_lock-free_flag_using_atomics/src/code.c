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

atomic_flag lock_flag = ATOMIC_FLAG_INIT;

void flag_set();
void flag_clear();
bool flag_test();

void flag_set()
{
    // atomic_store(&lock_flag, true);
    atomic_flag_test_and_set(&lock_flag);
}

void flag_clear()
{
    atomic_flag_clear(&lock_flag);
}

bool flag_test()
{
    /* get previous state */
    bool prior_state = atomic_flag_test_and_set(&lock_flag);

    if (!prior_state) {
        /* if the flag was not set, clear it */
        atomic_flag_clear(&lock_flag);
    }

    return prior_state;
}



int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    bool my_bool = flag_test();
    DEBUG_PRINT("Flag test: %d\n", my_bool);
    flag_set();
    DEBUG_PRINT("Flag set: %d\n", flag_test());
    flag_clear();
    DEBUG_PRINT("Flag cleared: %d\n", flag_test());


    return 0;
}
