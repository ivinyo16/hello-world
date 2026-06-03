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

void addBooleanArray(bool *array_A, bool *array_B, bool *add_array, int input_size);

void addBooleanArray(bool *array_A, bool *array_B, bool *add_array, int input_size)
{
    bool carry = 0;
    int temp_sum; 
    for ( int i = 0; i < input_size ; i++ )
    {
        temp_sum = array_A[i] + array_B[i] + carry;
        add_array[i] = temp_sum % 2;
        carry = temp_sum / 2;

    }
    add_array[input_size] = carry;

}

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

void printBooleanArray(bool *array, int size)
{
    for ( int i = 0 ; i < size ; i++ )
    {
        DEBUG_PRINT("%d ", array[i]);
    }
    DEBUG_PRINT("\n\n");
}

void createRandomArray(int8_t *array, int size)
{

    for (int i = 0 ; i  < size ; i++ )
    {
        array[i] = rand() % 10;
    }
}

void createRandomBooleanArray(bool *array, int size)
{
    for (int i = 0 ; i  < size ; i++ )
    {
        array[i] = rand() % 2;
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


    #define MAX_SIZE 50

    srand(time(NULL));


    bool input_array_A[MAX_SIZE] = {0};
    bool input_array_B[MAX_SIZE] = {0};
    bool output_array[MAX_SIZE+1] = {0};



    createRandomBooleanArray(input_array_A, MAX_SIZE);
    createRandomBooleanArray(input_array_B, MAX_SIZE);

    addBooleanArray(input_array_A, input_array_B, output_array, MAX_SIZE);
    



    printBooleanArray(input_array_A, MAX_SIZE);
    printBooleanArray(input_array_B, MAX_SIZE);
    printBooleanArray(output_array, MAX_SIZE+1);

    




    return 0;
}
