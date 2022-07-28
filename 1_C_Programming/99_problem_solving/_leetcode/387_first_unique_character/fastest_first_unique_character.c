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


//table size due to constraint, to ensure all elements can be traversed, it is best for the table size to be a prime number
#define TABLE_SIZE 26
//prime number for our second hashing method
#define PRIME 23

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

struct info
{
    int count;
    int first_instance_index;
};

int firstUniqChar(char * s)
{
    struct info info[TABLE_SIZE];
    int table[TABLE_SIZE] = {0};
    int hash_index = 0;
    int index = 0;
    char *c = s;
    int i = 0;
    int answer = -1;
    int unique_character_index_first = INT_MAX;
    bool is_there_unique = false;

    for( i = 0; i < TABLE_SIZE ; i++ )
    {
        info[i].count = 0;
        info[i].first_instance_index = -1;
    }

    while(*c != '\0' )
    {
        hash_index = hashFunction(*c);
        table[hash_index]++;
        info[hash_index].count++;
        if( info[hash_index].first_instance_index < 0)
        {
            info[hash_index].first_instance_index = index;
            DEBUG_PRINT("%c, index %d, hash_index: %d\n", *c, info[hash_index].first_instance_index, hash_index);

        }
        c++;
        index++;
    }

    for( i = 0 ; i < TABLE_SIZE ; i++)
    {
        DEBUG_PRINT("info[%d]: %d\n", i, info[i].count);
        if(info[i].count == 1)
        {
            DEBUG_PRINT("info[%d].first_instance_index %d\n", i, info[i].first_instance_index);
            is_there_unique = true;
            if ( info[i].first_instance_index < unique_character_index_first)
            {
                unique_character_index_first = info[i].first_instance_index;
                DEBUG_PRINT("unique_character_index_first %d\n", unique_character_index_first);
            }
        }
    }
    if(is_there_unique)
    {
        return unique_character_index_first;
    }
    else{
        return -1;
    }

    
}



int main(int argc, char* argv[])
{
    char *string = "aabb";
    int result = 0;

    result = firstUniqChar(string);

    printf("unique character found at index %d\n", result);


    return 0;
}
