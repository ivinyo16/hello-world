/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-22
 * 
 * 
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Example 2:
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * 
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
#include <time.h>

#include "utils.h"
#include "utils_array.h"
#include "header.h"


void swapElement(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void insertionSort(int *input, int *output, int size)
{
    // memcpy(output , input , size);

    // add first element to "sorted" pile
    output[0] = input[0];

    for ( int i = 1; i < size ; i++ )
    {
        // add new element to "sorted" pile
        output[i] = input[i];
        for ( int j = i; j > 0 ; j--)
        {
            if( output[j] < output[j-1] )
            {
                swapElement(&output[j], &output[j-1]);
            }
            else
            {
                break;
            }
        }
    }


}

int main(int argc, char* argv[])
{
    #define MAX_SIZE_A 4
    #define MAX_SIZE_B 4
    int input_array_A[MAX_SIZE_A] = {0};
    int sorted_array_A[MAX_SIZE_A] = {0};
    int input_array_B[MAX_SIZE_B] = {0};
    int sorted_array_B[MAX_SIZE_B] = {0};
    double result;

    srand(time(NULL));
    createRandomArray(input_array_A, MAX_SIZE_A);
    createRandomArray(input_array_B, MAX_SIZE_B);
    

    insertionSort(input_array_A, sorted_array_A, MAX_SIZE_A);
    insertionSort(input_array_B, sorted_array_B, MAX_SIZE_B);

    // printArray(input_array_A, MAX_SIZE_A);
    // printArray(input_array_B, MAX_SIZE_B);
    printArray(sorted_array_A, MAX_SIZE_A);
    printArray(sorted_array_B, MAX_SIZE_B);

    result = findMedianSortedArrays(sorted_array_A, MAX_SIZE_A, sorted_array_B, MAX_SIZE_B);

    DEBUG_PRINT("MEDIAN: %f\n", result);

    return 0;
}
