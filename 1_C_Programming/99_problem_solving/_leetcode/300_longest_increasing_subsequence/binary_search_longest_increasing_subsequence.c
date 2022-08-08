/**
 * @file longest_increasing_subsequence.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 * 
 * A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the 
 * remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 * Example 2:
 * 
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * Example 3:
 * 
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 *  
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 2500
 * -104 <= nums[i] <= 104
 * 
 * techniques used:
 * - binary search
 * 
 * @version 0.1
 * @date 2022-08-07
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


int lengthOfLIS(int* nums, int numsSize)
{
    int len = 0;
    int biggest = nums[0];
    for( int  i = 0 ; i < numsSize ; i++)
    {
        if(len == 0 || nums[len-1] < nums[i])
        {
            DEBUG_PRINT("%d, ", nums[i]);
            nums[len++] = nums[i];
            
        }
        else
        {
            for(int j = 0; j < len ; j++)
            {
                if(nums[i] <= nums[j])
                {
                    nums[j] = nums[i];
                    break;
                }
            }
        }
    }
    return len;
}

int main(int argc, char* argv[])
{
    int nums[] = {10 , 9 , 2 , 5 , 3, 7 , 101 , 18};
    // int nums[] = {10 , 9 , 4 , 2 , 3, 1 , 7 , 11, 18};
    // int nums[] =  {4,10,4,3,8,9};
    int size = sizeof(nums)/sizeof(nums[0]);
    int answer = lengthOfLIS(nums, size);

    printf("longest subsequence: %d\n", answer);



    return 0;
}
