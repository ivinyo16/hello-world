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

void countingSort(uint8_t *input, uint8_t *output, int size)
{

    uint8_t count_array[UINT8_MAX+1] = {0};
    //count 
    for ( int i = 0 ; i < size ; i++ )
    {
        count_array[input[i]]++;
    }
    // printArray(count_array, UINT8_MAX);

    //populate to output array
    int output_index = 0;
    for( int i = 0 ; i <= UINT8_MAX ; i++ )
    {
        if(count_array[i] != 0)
        {
            for ( int j = 0 ; j < count_array[i] ; j++,output_index++)
            {
                output[output_index] = i;
            }
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
    // srand(time(NULL));
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
    #define MAX_SIZE 100
    uint8_t input_array[MAX_SIZE] = {0};
    uint8_t result_array[MAX_SIZE] = {0};

    createRandomArray(input_array, MAX_SIZE);
    // printArray(input_array, MAX_SIZE);
    // createAscendingArray(input_array, MAX_SIZE);
    

    countingSort(input_array, result_array, MAX_SIZE);

    // printArray(input_array, MAX_SIZE);
    printArray(result_array, MAX_SIZE);




    return 0;
}
