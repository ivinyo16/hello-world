/**
 * @file is_anagram.c
 * @author your name (you@domain.com)
 * @brief Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 * 
 *  techniques used:
 *      - hash map
 * 
 * @version 0.1
 * @date 2022-07-28
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

#define MAP_SIZE           26 //lowercase letters of the alphabet english

bool isAnagram(char * s, char * t)
{
    int first_string_len = strlen(s);
    int second_string_len = strlen(t);
    int second_string_ctr = second_string_len;
    int first_char_map[MAP_SIZE] = {0};
    int second_char_map[MAP_SIZE] = {0};
    DEBUG_PRINT("first_string_len: %d\n", first_string_len);

    if(first_string_len != second_string_len)
    {
        return false;
    }

    for(int i = 0; i < first_string_len ; i++ )
    {
        first_char_map[s[i] - 'a']++;
        second_char_map[t[i] - 'a']++;
    }

    if( memcmp(first_char_map, second_char_map, sizeof(first_char_map)) != 0 )
    {
        return false;
    }

    // for(int i = 0; i < MAP_SIZE ; i++ )
    // {
    //     if(first_char_map[i] != second_char_map[i])
    //     {
    //         return false;
    //     }
    // }


    return true;
}

int main(int argc, char* argv[])
{
    bool answer = false;
    char *first = "car";
    char *second = "rcb";

    answer = isAnagram(first, second);

    printf("is Anagram: %s\n", answer ? "true" : "false");

    return 0;
}
