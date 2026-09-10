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

int parse(const char* s);

int parse(const char* s)
{
    int result = -1;
    int max_string_length = 256;
    int eq_index = -1;
    int ctr = 0;

    /* Check if the input string is NULL */
    if (s == NULL)
    {
        DEBUG_PRINT("Input string is NULL\n");
        return result;
    }

    for ( ctr = 0 ; ctr < max_string_length && s[ctr] != '\0'; ctr++)
    {
        if( s[ctr] == '=')
        {
            DEBUG_PRINT("Found '=' at index %d\n", ctr);
            eq_index = ctr;
            break;
        }
    }

    if (eq_index == -1)
    {
        DEBUG_PRINT("No '=' found in the string\n");
        return result;
    }

    if( strncmp(s, "SPEED", eq_index) == 0)
    {
        DEBUG_PRINT("Found SPEED command\n");
        result = 0;

        /* Convert the value to an integer */
        result = strtol(s + eq_index + 1, NULL, 10);
    }




    return result;
}

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    // const char* s = "SPEED=-100";
    const char* s = "BAD";
    DEBUG_PRINT("Input string: %s\n", s);
    parse(s);
    DEBUG_PRINT("Parsed value: %d\n", parse(s));




    return 0;
}
