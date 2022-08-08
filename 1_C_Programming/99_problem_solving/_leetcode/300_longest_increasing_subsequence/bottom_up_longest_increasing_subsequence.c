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


void printMatrix(int m, int n, int matrix[][n])
{
    int i,j;
    for( i = 0 ; i < m ; i++ )
    {
        for( j = 0 ; j < n ; j++ )
        {
            printf("%d, ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief 
 * 
 * @param nums array in question
 * @param numsSize size of array
 * @param index current starting index
 * @param prev_i 
 * @param dp 
 * @return int 
 */
int lengthOfLISAux(int *nums, int numsSize,  int index, int prev_i, int dp[][numsSize+1])
{
    int ans = 0;
    int dont_take = 0;
    int take = 0;

    if(index >= numsSize)
    {
        return 0;
    }
    if(dp[index][prev_i+1] != -1)
    {
        return dp[index][prev_i+1];
    }
    dont_take = lengthOfLISAux(nums, numsSize, index + 1, prev_i, dp);
    if(prev_i == -1 || nums[index] > nums[prev_i])
    {
        take = 1 + lengthOfLISAux(nums, numsSize, index + 1, index, dp);
    }
    dp[index][prev_i+1] = (take >= dont_take) ? take : dont_take;
    DEBUG_PRINT("%d %d\n", index, prev_i+1);
    return dp[index][prev_i+1];


}

int lengthOfLIS(int* nums, int numsSize)
{
    int dp[numsSize];
    int ans = 1;
    for(int i = 0; i < numsSize ; i++)
    {
        dp[i] = 1;
    }

    for( int i = 0 ; i < numsSize ; i++ )
    {
        for( int j = 0; j < i ; j++ )
        {
            if( nums[i] > nums[j] )
            {
                dp[i] = dp[i] >= dp[j]+1 ? dp[i] : dp[j]+1;
                ans = ans >= dp[i] ? ans : dp[i];
            }
        }
    }
    for( int i = 0 ; i < numsSize ; i++ )
    {
        DEBUG_PRINT("%d, ", dp[i]);
    }
    DEBUG_PRINT("\n");
    return ans;
}

int main(int argc, char* argv[])
{
    // int nums[] = {10 , 9 , 2 , 5 , 3, 7 , 101 , 18};
    // int nums[] = {10 , 9 , 4 , 2 , 3, 1 , 7 , 11, 18};
    int nums[] =  {4,10,4,3,8,9};
    // int nums[] = {3,2,4};
    int size = sizeof(nums)/sizeof(nums[0]);
    int answer = lengthOfLIS(nums, size);

    printf("longest subsequence: %d\n", answer);



    return 0;
}
