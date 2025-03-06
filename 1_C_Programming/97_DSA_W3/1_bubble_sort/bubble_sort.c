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

void swapElement(int8_t *a, int8_t *b)
{
    int8_t temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void bubbleSort(int8_t *input, int8_t *output, int size)
{
    memcpy(output , input , size);
    bool has_swap;

    for (int unsorted_size = size ; unsorted_size > 0 ; unsorted_size--)
    {
        has_swap = false;
        for (int i = 0 ; i < unsorted_size-1 ; i++)
        {
            if ( output[i] > output[i+1] )
            {
                swapElement( &output[i], &output[i+1]);
                has_swap = true;
            }
        }
        if (!has_swap)
        {
            break;
        }
    }

}

void printArray(int8_t *array, int size)
{
    for ( int8_t i = 0 ; i < size ; i++ )
    {
        DEBUG_PRINT("%d ", array[i]);
    }
    DEBUG_PRINT("\n\n");
}

void createRandomArray(int8_t *array, int size)
{
    // srand(time(NULL));
    for (int i = 0 ; i  < size ; i++ )
    {
        array[i] = rand() & INT8_MAX;
    }
}

void createAscendingArray(int8_t *array, int size)
{
    // srand(time(NULL));
    for (int i = 0 ; i  < size ; i++ )
    {
        array[i] = i < INT8_MAX ? i : INT8_MAX;
    }
}

int main(int8_t argc, char* argv[])
{
    #define MAX_SIZE 20000
    int8_t input_array[MAX_SIZE] = {0};
    int8_t result_array[MAX_SIZE] = {0};

    // createRandomArray(input_array, MAX_SIZE);
    createAscendingArray(input_array, MAX_SIZE);
    

    bubbleSort(input_array, result_array, MAX_SIZE);

    // printArray(input_array, MAX_SIZE);
    // printArray(result_array, MAX_SIZE);




    return 0;
}
