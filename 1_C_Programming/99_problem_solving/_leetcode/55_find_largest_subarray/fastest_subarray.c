/**
 * @file find_largest_subarray.c
 * @author Ivin Lim (ivin.lim16@gmail.com)
 * @brief given an array, find within the array the subarray with the largest cumulative sum of its elements
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <limits.h> // for MAX_INT

typedef struct s_subarray_info
{
    /* data */
    unsigned int left_index;
    unsigned int right_index;
    int cumulative_sum;
} s_subarray_info;

s_subarray_info findMaxSubCrossing(int sub_array[], unsigned int low, unsigned int mid, unsigned int high)
{
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    int max_left, max_right;
    int i = 0;
    s_subarray_info subarray_info = {
        .left_index = 0,
        .right_index = 0,
        .cumulative_sum = 0,
    };
    int x=0;

    for ( i = (int)mid ; i >= (int)low ; i--)
    {
        sum += sub_array[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for ( i = (int) mid + 1 ; i <= (int)high ; i++)
    {
        sum += sub_array[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    subarray_info.left_index = max_left;
    subarray_info.right_index = max_right;
    subarray_info.cumulative_sum = left_sum + right_sum;
    return subarray_info;
}

s_subarray_info findMaxSubarray(int sub_array[], unsigned int low, unsigned int high)
{
    s_subarray_info subarray_info = {
        .left_index = 0,
        .right_index = 0,
        .cumulative_sum = 0,
    };
    s_subarray_info left_subarray_info = {
        .left_index = 0,
        .right_index = 0,
        .cumulative_sum = 0,
    };
    s_subarray_info right_subarray_info = {
        .left_index = 0,
        .right_index = 0,
        .cumulative_sum = 0,
    };
    s_subarray_info cross_subarray_info = {
        .left_index = 0,
        .right_index = 0,
        .cumulative_sum = 0,
    };


    int mid;

    if(high == low)
    {
        subarray_info.left_index = low;
        subarray_info.right_index = high;
        subarray_info.cumulative_sum = sub_array[low];
        return subarray_info;
    }
    else
    {
    mid = (low+high)/2;

        left_subarray_info = findMaxSubarray(sub_array, low, mid);
        right_subarray_info = findMaxSubarray(sub_array, mid+1, high);
        cross_subarray_info = findMaxSubCrossing(sub_array, low, mid, high);

        if(left_subarray_info.cumulative_sum >= right_subarray_info.cumulative_sum 
            && left_subarray_info.cumulative_sum >= cross_subarray_info.cumulative_sum)
        {
            return left_subarray_info;
        }
        if(right_subarray_info.cumulative_sum >= left_subarray_info.cumulative_sum 
            && right_subarray_info.cumulative_sum >= cross_subarray_info.cumulative_sum)
        {
            return right_subarray_info;
        }
        else
        {
            return cross_subarray_info;
        }
    }
}

int maxSubArray(int* nums, int numsSize)
{
    int max = nums[0];
    int current = 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        current += nums[i];
        if (max < current) {
            max = current;
        }
        
        if (current < 0) {
            current = 0;
        }
    }
    
    return max;
}

int main(int argc, char* argv[])
{
    int stock_prices[] = {1, 2, -3, -4, 5, 6, -2 , 1, -2, 5, -8};
    int lower_limit = 0;
    int upper_limit = 10;
    s_subarray_info result = findMaxSubarray(stock_prices, lower_limit, upper_limit);

    printf("lower index: %u\n", result.left_index);
    printf("upper index: %u\n", result.right_index);
    printf("cumulative sum: %u\n", result.cumulative_sum);

    return 0;
}
