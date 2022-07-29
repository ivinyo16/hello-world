/**
 * @file ransom_note.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 * 
 * Each letter in magazine can only be used once in ransomNote.
 * 
 * Example 1:
 * 
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
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

#define MAP_SIZE    26

bool canConstruct(char * ransomNote, char * magazine)
{
    int len_ransom = strlen(ransomNote);
    int len_magazine = strlen(magazine);
    int magazine_map[MAP_SIZE] = {0};

    //1. if len of magazine is less than ransom, not possible
    if( len_magazine < len_ransom )
    {
        return false;
    }

    //2. insert magazine into hashmap
    for(int i = 0 ; i < len_magazine ; i++ )
    {
        magazine_map[magazine[i] - 'a']++;
    }

    //3. check ransom chars if magazine map accodmodates it
    for(int i = 0 ; i < len_ransom ; i++ )
    {
        if(--magazine_map[ransomNote[i] - 'a'] < 0 )
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    char *ransom = "impossible";
    char *magazine = "isqqsnnivvmzzozzpjjbeewwl";
    bool answer = false;

    answer = canConstruct(ransom, magazine);
    printf("can? %s\n", answer ? "true" : "false" );


    return 0;
}
