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

void insertionSort(int8_t *input, int8_t *output, int size)
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
    #define MAX_SIZE 50000
    int8_t input_array[MAX_SIZE] = {0};
    int8_t result_array[MAX_SIZE] = {0};

    // createRandomArray(input_array, MAX_SIZE);
    createAscendingArray(input_array, MAX_SIZE);
    

    insertionSort(input_array, result_array, MAX_SIZE);

    // printArray(input_array, MAX_SIZE);
    // printArray(result_array, MAX_SIZE);




    return 0;
}
