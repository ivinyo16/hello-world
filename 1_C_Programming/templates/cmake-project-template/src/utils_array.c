/**
 * @file utils_array.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-06-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */

/* Standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#include "utils_array.h"
#include "utils.h"



void printArray(int *array, int size)
{
    for ( int i = 0 ; i < size ; i++ )
    {
        DEBUG_PRINT("%d ", array[i]);
    }
    DEBUG_PRINT("\n\n");
}

void createRandomArray(int *array, int size)
{
    // srand(time(NULL));


    for (int i = 0 ; i  < size ; i++ )
    {
        array[i] = rand() & INT8_MAX;
    }
}

void createAscendingArray(int *array, int size)
{
    // srand(time(NULL));
    for (int i = 0 ; i  < size ; i++ )
    {
        array[i] = i < INT8_MAX ? i : INT8_MAX;
    }
}