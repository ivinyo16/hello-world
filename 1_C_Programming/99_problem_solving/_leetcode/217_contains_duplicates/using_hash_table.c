/**
 * @file contains_duplicate.c
 * @author Ivin Lim (you@domain.com)
 * @brief Given an integer array nums, return true if any value appears at least twice in the array,
 *        and return false if every element is distinct.
 * 
 * Example:
 *      Input: nums = [1,2,3,1]
*       Output: true
 *
 * Constraints:
 *       1 <= nums.length <= 105
 *      -109 <= nums[i] <= 109
 * 
 * 
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

//using our current hash function, we can allot SIZE unqiue hashcodes.
#define SIZE 100000

struct DataItem 
{
   int data;
   int key;
   struct DataItem *next;
};
 
struct DataItem* item;
struct DataItem *hash_array[SIZE];

/**
 * @brief 
 * 
 * @param hash_array hash array that could be inserted
 * @param keys 
 * @param numsSize 
 * @return true 
 * @return false 
 */

int hashFunction(int key)
{
    return key % SIZE;
}

bool insertTable(struct DataItem **hash_array, int key, int numsSize)
{
    int hashIndex = 0;

    //Allocate new space for new item
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = key;
    item->key = key;

    //1. Calculate Hashindex, just do simple modulo over table size
    hashIndex = hashFunction(key);


    while( hash_array[hashIndex] != NULL )
    {
        printf("key: %d\n", key);
        printf("hash_array[hashIndex]->key: %d\n", hash_array[hashIndex]->key);
        if( hash_array[hashIndex]->key == key)
        {
            return false;
        }
        hash_array[hashIndex] = hash_array[hashIndex]->next;
    }

    hash_array[hashIndex] = item;

    //3. Check keys of non empty slot

    return true;

}

bool containsDuplicate(int* nums, int numsSize)
{

    int i = 0;
    int key = 0;


    for( i = 0 ; i < numsSize ; i++ )
    {
        hash_array[i] = NULL;
    }

    for( i = 0 ; i < numsSize ; i++ )
    {
        key = nums[i];
        if( insertTable(hash_array, key, numsSize) == false)
        {
            return true;
        }
    }
    

    return false;
}

int main(int argc, char* argv[])
{
    // int numSize = 11;
    // int nums[] = {1,2,3,4,5,6,7,8,5,123,14};
    int numSize = 2;
    int nums[] = {3,1};
    bool result = false;


    //============================
    result = containsDuplicate(nums, numSize);

    printf("contains duplicate: %s\n", result ? "true" : "false");

    return 0;
}
