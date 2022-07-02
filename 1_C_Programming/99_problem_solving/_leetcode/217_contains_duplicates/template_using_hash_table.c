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
#define SIZE 20

struct DataItem 
{
   int data;
   int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) 
{
    return key % SIZE;
}

/**
 * @brief Search element given a key
 * 
 * @param key 
 * @return struct DataItem* 
 */
struct DataItem *search(int key) 
{
    //get the hash 
    int hashIndex = hashCode(key);  

    //move in array until an empty 
    while(hashArray[hashIndex] != NULL) 
    {

        if(hashArray[hashIndex]->key == key)
            return hashArray[hashIndex]; 
            
        //go to next cell
        ++hashIndex;
        
        //wrap around the table
        hashIndex %= SIZE;
    }        

    return NULL;        
}

/**
 * @brief 
 * 
 * @param key 
 * @param data 
 */
void insert(int key,int data) 
{
    //Allocate new space for new item
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = data;  
    item->key = key;

    //get the hash 
    int hashIndex = hashCode(key);



    //move in array until an empty or deleted cell
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) 
    {
        //go to next cell
        ++hashIndex;
        //wrap around the table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item)
{
    int key = item->key;

    //get the hash 
    int hashIndex = hashCode(key);

    //move in array until an empty
    // while hashArray at hashIndex is not NULL, do this routine
    while(hashArray[hashIndex] != NULL) 
    {
        
        //if  current key matches our input key
        if(hashArray[hashIndex]->key == key) 
        {
            struct DataItem* temp = hashArray[hashIndex]; 
            
            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem; 
            return temp;
        }
        
        //go to next cell
        ++hashIndex;
        
        //wrap around the table
        hashIndex %= SIZE;
    }      

    return NULL;
}

void display() 
{
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

void myInsert( struct DataItem** hash_array, int key,int data) 
{

}


bool containsDuplicate(int* nums, int numsSize)
{
    struct DataItem* our_hash_array[numsSize]; 
    return false;
}

int main(int argc, char* argv[])
{
    int numSize = 11;
    int nums[] = {1,2,3,4,5,6,7,8,9, 123, 5};
    bool result = false;

    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    dummyItem->data = -1;  
    dummyItem->key = -1; 

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    display();
    item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

   delete(item);
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }


    //============================
    result = containsDuplicate(nums, numSize);

    printf("contains duplicate: %s\n", result ? "true" : "false");

    return 0;
}
