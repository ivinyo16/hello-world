/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief 
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
#include <stdint.h>
#include <limits.h>
#include <time.h>


#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

void printArray(uint8_t *array, int size);

void swapElement(uint8_t *a, uint8_t *b)
{
    uint8_t temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

// Function to merge two subarrays
void merge(uint8_t arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    free(L);
    free(R);
}

void iterativeMergeSort(uint8_t *input, uint8_t *output, int size)
{
    memcpy(output,input,size);
    int curr_size;  // Current size of subarrays to be merged
    int left_start; // Starting index of left subarray to be merged

    // Merge subarrays in bottom-up manner. First merge subarrays of size 1
    // to create sorted subarrays of size 2, then merge subarrays of size 2
    // to create sorted subarrays of size 4, and so on.
    for (curr_size = 1; curr_size <= size - 1; curr_size = 2 * curr_size) {
        // Pick starting point of different subarrays of current size
        for (left_start = 0; left_start < size - 1; left_start += 2 * curr_size) {
            // Find ending point of left subarray. mid+1 is starting point of right
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < size - 1) ? 
                            left_start + 2 * curr_size - 1 : size - 1;

            // Merge subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(output, left_start, mid, right_end);
        }
    }
}

void printArray(uint8_t *array, int size)
{
    for ( uint8_t i = 0 ; i < size ; i++ )
    {
        DEBUG_PRINT("%d ", array[i]);
    }
    DEBUG_PRINT("\n\n");
}

void createRandomArray(uint8_t *array, int size)
{
    srand(time(NULL));
    for (int i = 0 ; i  < size ; i++ )
    {
        array[i] = rand() & UINT8_MAX;
    }
}

void createAscendingArray(uint8_t *array, int size)
{
    srand(time(NULL));
    for (int i = 0 ; i  < size ; i++ )
    {
        array[i] = i < UINT8_MAX ? i : UINT8_MAX;
    }
}

int main(uint8_t argc, char* argv[])
{
    #define MAX_SIZE 10
    uint8_t input_array[MAX_SIZE] = {0};
    uint8_t result_array[MAX_SIZE] = {0};

    createRandomArray(input_array, MAX_SIZE);
    // printArray(input_array, MAX_SIZE);
    // createAscendingArray(input_array, MAX_SIZE);
    

    iterativeMergeSort(input_array, result_array, MAX_SIZE);

    printArray(input_array, MAX_SIZE);
    printArray(result_array, MAX_SIZE);




    return 0;
}
