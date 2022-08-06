/**
 * @file combination_sum_iv.c
 * @author your name (you@domain.com)
 * @brief 
 *  WARNING: this is actually finding number of permutations
 *  Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
 * 
 * The test cases are generated so that the answer can fit in a 32-bit integer.
 * 
 * Example 1:
 *      
 *      Input: nums = [1,2,3], target = 4
 *      Output: 7
 *      Explanation:
 *      The possible combination ways are:
 *      (1, 1, 1, 1)
 *      (1, 1, 2)
 *      (1, 2, 1)
 *      (1, 3)
 *      (2, 1, 1)
 *      (2, 2)
 *      (3, 1)
 *      Note that different sequences are counted as different combinations.
 * 
 *  techniques:
 *  - dynamic programming
 * 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**

/* Standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

// #define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

int combinationSum4Aux(int* nums, int numsSize, int target, int hash[])
{
    int ans = 0;
    if(target == 0)
    {
        DEBUG_PRINT("ADD\n");
        return 1;
    }

    if(hash[target] != -1)
    {
        DEBUG_PRINT("use cache hash[%d] = %d\n", target, hash[target]);
        return hash[target];
    }
    
    for(int i = 0; i < numsSize ; i++)
    {
        if(nums[i] <= target)
        {
            DEBUG_PRINT("BEFORE nums[%d]: %d , target: %d, target-nums[i]: %d , ans: %d\n", i, nums[i], target, target-nums[i], ans);
            ans += combinationSum4Aux(nums+i, numsSize-i, target - nums[i], hash);
            DEBUG_PRINT("AFTER nums[%d]: %d , target: %d, target-nums[i]: %d , ans: %d\n", i, nums[i], target, target-nums[i], ans);
        }
    }
    DEBUG_PRINT("hash[%d]: %d\n\n", target, ans);
    return hash[target] = ans;

}

void printArray(int *arr, int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int combinationSum4(int* nums, int numsSize, int target)
{
    int hash[target+1];
    int ans = 0;

    for( int i = 0 ; i < target+1 ; i++ )
    {
        hash[i] = -1;
    }

    qsort(nums, numsSize, sizeof(int), cmpfunc);
    printArray(nums, numsSize);

    ans = combinationSum4Aux(nums, numsSize, target, hash);

    return ans;
}

int main(int argc, char* argv[])
{
    int arr[] = {1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 3;
    int answer = combinationSum4(arr, size, target);


    printf("number of combinations is %d\n", answer);
    


    return 0;
}
