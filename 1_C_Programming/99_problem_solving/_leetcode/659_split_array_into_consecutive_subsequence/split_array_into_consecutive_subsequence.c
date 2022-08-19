/**
 * @file split_array_into_consecutive_subsequence.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * You are given an integer array nums that is sorted in non-decreasing order.
 * 
 * Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:
 * 
 * Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
 * All subsequences have a length of 3 or more.
 * Return true if you can split nums according to the above conditions, or false otherwise.
 * 
 * A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,3,4,5]
 * Output: true
 * Explanation: nums can be split into the following subsequences:
 * [1,2,3,3,4,5] --> 1, 2, 3
 * [1,2,3,3,4,5] --> 3, 4, 5
 * Example 2:
 * 
 * Input: nums = [1,2,3,3,4,4,5,5]
 * Output: true
 * Explanation: nums can be split into the following subsequences:
 * [1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
 * [1,2,3,3,4,4,5,5] --> 3, 4, 5
 * Example 3:
 * 
 * Input: nums = [1,2,3,4,4,5]
 * Output: false
 * Explanation: It is impossible to split nums into consecutive increasing subsequences of length 3 or more.
 *  
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 104
 * -1000 <= nums[i] <= 1000
 * nums is sorted in non-decreasing order.
 * 
 * Techniques used:
 * - hash map
 * 
 * @version 0.1
 * @date 2022-08-18
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

#define TABLE_SIZE 2005

bool isPossible(int* nums, int numsSize)
{

    
    int map[TABLE_SIZE] = {0};
    int last_consecutive_of_a_subset[TABLE_SIZE] = {0};
    int offset = 1001; //since our numbers can be up to -1000
    int last_consecutive_used_third = 0;

    if (numsSize < 3)
    {
        return false;
    }

    for(int i = 0 ; i < numsSize ; i++ )
    {
        map[nums[i] + offset]++;
    }

    // DEBUG_PRINT("%d\n", map[10+1000]);

    for (int i = 0 ; i < numsSize ; i++ )
    {
        if( map[nums[i]+ offset] <= 0 )
        {
            continue;
        }
        if( last_consecutive_of_a_subset[nums[i]-1+ offset] > 0)
        {
            last_consecutive_of_a_subset[nums[i]-1+ offset]--;
            last_consecutive_of_a_subset[nums[i]+ offset]++;
            map[nums[i] + offset]--;
        }
        else if( map[nums[i]+1+ offset] >= 1 && map[nums[i]+2+ offset] >= 1)
        {
            map[nums[i]+ offset]--;
            map[nums[i]+1+ offset]--;
            map[nums[i]+2+ offset]--;
            last_consecutive_of_a_subset[nums[i]+2+ offset]++;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[])
{
    // int arr[] = {1,2,3,3,4,4,5,5};    //true
    // int arr[] = {1,2,3,4,4,5,5};    //false
    // int arr[] = {1,2,3,4,4,6,7,8,9,10,11};   //false
    // int arr[] = {4,5,6,6,7,8,9,10,10,11}; // false
    // int arr[] = {1,2,3,4,5,5,6,7};    //true
    // int arr[] = {1,2,3,3,4,4,5};    //true
     int arr[] = {1,2,3,3,4,4,5,5};    //true
    int size = sizeof(arr)/sizeof(arr[0]);
    bool answer = 0;

    answer = isPossible(arr, size);
    printf("answer: %s\n", answer ? "true" : "false");
    return 0;
}