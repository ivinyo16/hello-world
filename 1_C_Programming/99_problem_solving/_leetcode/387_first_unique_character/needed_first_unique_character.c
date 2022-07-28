/**
 * @file needed first_unique_character.c
 * @author your name (you@domain.com)
 * @brief Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
 * for leetcode time constraint, instead all the characters first, first hit we return asap
 * @version 0.1
 * @date 2022-07-16
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

// #define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif


int firstUniqChar(char * s){
    int map[26]={0};
    int slen = strlen(s);       //length of string
    for(int i=0;i<slen ;i++)
    {
        map[s[i]-'a']++;
    }
    
    for(int i=0;i<slen;i++)
    {
        if(map[s[i]-'a']==1)return i;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    char *string = "loveleetcode";
    int result = 0;

    result = firstUniqChar(string);

    printf("unique character found at index %d\n", result);


    return 0;
}
