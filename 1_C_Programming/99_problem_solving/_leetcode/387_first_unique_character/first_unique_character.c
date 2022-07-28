/**
 * @file first_unique_character.c
 * @author your name (you@domain.com)
 * @brief Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
 *      Techniques Used:
 *      - Hash Tables using chaining
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

// #define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif


//table size due to constraint, to ensure all elements can be traversed, it is best for the table size to be a prime number
#define TABLE_SIZE 29
//prime number for our second hashing method
#define PRIME 23

typedef struct s_data_node
{
    int key;
    int data;
    struct s_data_node *next;
    struct s_data_node *prev;
}s_data_node;



int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

int insertNode(s_data_node **hash_table, int key)
{
    int hash_index = hashFunction(key);
    // DEBUG_PRINT("hash_index %d\n", hash_index);
    s_data_node *current_node = hash_table[hash_index];
    s_data_node *head = hash_table[hash_index];

    //1. allocate new node
    s_data_node *new_node = (s_data_node*)malloc(sizeof(s_data_node));
    new_node->key = key;
    new_node->data = key; //for this case, we just put key in data field as well
    new_node->next = NULL;


    //3. check if we are currently empty(first index)
    if(current_node == NULL)
    {
        current_node = new_node;
        current_node->prev = NULL;
        hash_table[hash_index] = current_node;
        // DEBUG_PRINT("%p, %p\n", hash_table[hash_index], current_node);
    }
    else
    {
        //2. find empty next
        while(current_node->next != NULL)
        {
            current_node = current_node->next;
        }

        current_node->next = new_node;
        current_node->next->prev = current_node;

    }

    // DEBUG_PRINT("%p, %p\n", temp, current_node);
    

    return -1;
}

bool isUnique(s_data_node **hash_table,int key)
{
    int hash_index = hashFunction(key);
    if( hash_table[hash_index]->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int firstUniqChar(char * s)
{
    int index = 0;
    int unique_index = -1;
    //1. create unallocated hash table
    s_data_node *hash_table_1[TABLE_SIZE];
    //2. set to null
    for(int i = 0 ; i < TABLE_SIZE; i++)
    {
        hash_table_1[i] = NULL;
    }
    char *c = s;

    //3. insert all characters into hash table
    while(*c != '\0')
    {
        insertNode(hash_table_1,*c);
        c++;
    }

    c = s;
    while(*c != '\0')
    {
        if(isUnique(hash_table_1,*c))
        {
            // DEBUG_PRINT("unique! char %c\n", *c);
            unique_index = index;
            break; // we now have the first index
        }
        index++;
        c++;
    }

    return unique_index;
}



int main(int argc, char* argv[])
{
    char *string = "aabb";
    int result = 0;

    result = firstUniqChar(string);

    printf("unique character found at index %d\n", result);


    return 0;
}
