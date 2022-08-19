/**
 * @file reduce_array_to_half_size.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
 * 
 * Return the minimum size of the set so that at least half of the integers of the array are removed.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: arr = [3,3,3,3,5,5,5,2,2,7]
 * Output: 2
 * Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
 * Possible sets of size 2 are {3,5},{3,2},{5,2}.
 * Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
 * Example 2:
 * 
 * Input: arr = [7,7,7,7,7,7]
 * Output: 1
 * Explanation: The only possible set you can choose is {7}. This will make the new array empty.
 *  
 * 
 * Constraints:
 * 
 * 2 <= arr.length <= 10^5
 * arr.length is even.
 * 1 <= arr[i] <= 10^5
 * 
 * Techniqes used:
 *  - hash map
 * 
 * @version 0.1
 * @date 2022-08-17
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


#define TABLE_SIZE      100000

int cmpfunc(const void * a, const void * b) 
{
    return ( *(int *) b - *(int *)a );
}

void printArray(int *arr, int size)
{
    for(int i = 0 ; i < size ;  i++ )
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int minSetSize(int* arr, int arrSize)
{
    int target = arrSize / 2;
    int current_size = arrSize;
    int count = 0;

    int map[TABLE_SIZE] = {0};

    for(int i = 0 ; i < arrSize ; i++ )
    {
        map[arr[i]]++;
    }
    qsort(map, TABLE_SIZE, sizeof(int), cmpfunc);
    for(int i = 0 ; i < arrSize ; i++)
    {
        current_size -= map[i];
        count++;
        if(current_size <= target)
        {
            break;
        }
    }

    return count;
}

int main(int argc, char* argv[])
{
    int arr[] = {3,3,3,3,5,5,5,2,2,7};
    // int arr[] = {7,7,7,7,7,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int answer = 0;

    answer = minSetSize(arr, size);
    printf("answer: %d\n", answer);
    return 0;
}
