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

struct Node
{
    int val;
    struct Node *next;
};

struct Set
{
    int bucketSize;
    struct Node **table;
};

void initSet(struct Set *set, int bucketSize)
{
    set->bucketSize = bucketSize;
    set->table = malloc(sizeof(struct Node*) * bucketSize);
    memset(set->table, 0, sizeof(struct Node*) * bucketSize);
}

bool addValue(struct Set *s, int val)
{
    int idx = val > 0 ? val : -val;
    idx %= s->bucketSize;
    struct Node *ptr = s->table[idx];
    while(ptr != NULL)
    {
        if(ptr->val == val)
        {
            return false;
        }
    
        ptr = ptr->next;
    }
    ptr = malloc(sizeof(struct Node));
    ptr->val = val;
    ptr->next = s->table[idx];
    s->table[idx] = ptr;
    return true;
}
void releaseSet(struct Set *s)
{
    struct Node *ptr, *tmp;
    for(int i = 0; i < s->bucketSize; ++i)
    {
        ptr = s->table[i];
        while(ptr != NULL)
        {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    free(s->table);
    s->table = NULL;
    s->bucketSize = 0;
}
bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize < 2)
    {
        return false;
    }
    struct Set set;
    initSet(&set, numsSize / 2);
    for(int i = 0; i < numsSize; ++i)
    {
        if(!addValue(&set, nums[i]))
        {
            releaseSet(&set);
            return true;
        }
    }
    releaseSet(&set);
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
