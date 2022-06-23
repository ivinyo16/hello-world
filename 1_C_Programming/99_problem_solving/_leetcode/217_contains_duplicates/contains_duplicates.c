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


bool containsDuplicate(int* nums, int numsSize)
{
    int i= 0 , j = 0;

    for( i = 0 ; i < numsSize ; i++ )
    {
        for( j = i+1 ; j < numsSize ; j++)
        {
            if(nums[j] == nums[i])
            {
                return true;
            }
        }
    }


    return false;
}

int main(int argc, char* argv[])
{
    int numSize = 11;
    int nums[] = {1,2,3,4,5,6,7,8,9, 123, 5};
    bool result = false;

    result = containsDuplicate(nums, numSize);

    printf("contains duplicate: %s\n", result ? "true" : "false");

    return 0;
}
