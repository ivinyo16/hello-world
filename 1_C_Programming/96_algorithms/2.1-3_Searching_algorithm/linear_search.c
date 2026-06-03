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

#define UNUSED(x) (void)(x)

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

int findIndexOfElement(int8_t *input, int size, int element);

int findIndexOfElement(int8_t *input, int size, int element)
{
    int result = -1;
    UNUSED(input);
    UNUSED(element);
    for (int i = 0 ; i < size ; i++ )
    {
        if (input[i] == element)
        {
            result = i;
            break;
        }
    }
    return result;
}

void swapElement(int8_t *a, int8_t *b)
{
    int8_t temp;
    temp = *a;
    *a = *b;
    *b = temp;

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
    srand(time(NULL));


    for (int i = 0 ; i  < size ; i++ )
    {
        array[i] = rand() % 10;
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

int main(int argc, char* argv[])
{
    // Print the program name (always index 0)
    // printf("Program name: %s\n", argv[0]);

    // Loop through additional arguments
    for (int i = 1; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    int element = (int)atoi(argv[1]);

    #define MAX_SIZE 50
    int8_t input_array[MAX_SIZE] = {0};
    int result = 0;



    createRandomArray(input_array, MAX_SIZE);
    // createAscendingArray(input_array, MAX_SIZE);
    

    result = findIndexOfElement(input_array, MAX_SIZE, element);

    printArray(input_array, MAX_SIZE);
    DEBUG_PRINT("index: %d", result);

    




    return 0;
}
