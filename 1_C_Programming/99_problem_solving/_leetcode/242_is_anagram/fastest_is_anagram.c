/**
 * @file is_anagram.c
 * @author your name (you@domain.com)
 * @brief Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 * 
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

bool isAnagram(char * s, char * t){
    if (!s || !t)
        return false;
    
    int *alphabet = calloc(26, sizeof(int));
    if (!alphabet)
        return false;
    
    int *allzeros = calloc(26, sizeof(int));
    if (!allzeros)
        return false;
    
    while (*s) {
        alphabet[*s - 'a']++;
        s++;
    }
    
    while (*t) {
        alphabet[*t - 'a']--;
        t++;
    }
    
    if (!memcmp(alphabet, allzeros, 26 * sizeof(int)))
        return true;
    else
        return false;
}

int main(int argc, char* argv[])
{
    bool answer = false;
    char *first = "car";
    char *second = "rca";

    answer = isAnagram(first, second);

    printf("is Anagram: %s\n", answer ? "true" : "false");

    return 0;
}
