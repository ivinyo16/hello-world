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
#include <stdint.h>
#include <limits.h>

int memoizedCutRodAux(int price_array[], int size, int hash[])
{
    int price = 0;
    int max = INT_MIN;
    int idx = 0;
    
    //1. Check if we computed for this specific hash already
    if(hash[size-1] >= 0)
    {
        return hash[size-1];
    }

    if(size == 1)
    {
        max = 0;
    }
    else
    {
        price = INT_MIN;
        for( idx = 1 ; idx < size ;  idx++)
        {
            price = price_array[idx-1] + memoizedCutRodAux(price_array, size-idx, hash);
            if(price > max)
            {
                max = price;
            }
        }
    }
    hash[size-1] = max;
    return max;
}

int memoizedCutRod(int price_array[], int size)
{
    int max_price = -1;
    size++;         //allocate extra since array would start at index 0
    int hash[size];
    int idx = 0;
    for( idx = 0 ; idx < size ; idx++ )
    {
        hash[idx] = INT_MIN;
    }
    return memoizedCutRodAux(price_array, size, hash);


    return max_price;
}

int main(int argc, char* argv[])
{
    // int price_table_vs_inch[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int price_table_vs_inch[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 32, 35, 38, 39, 40, 47, 47, 50, 54, 60, 32, 35, 38, 39, 40, 47, 47, 50, 54, 60 };
    int size = sizeof(price_table_vs_inch)/sizeof(int);

    int current_sell;
    int best_length;

    current_sell = memoizedCutRod(price_table_vs_inch , size);

    printf("best length to sell rod at total %d inches is with revenue of %d\n", size, current_sell);

    return 0;
}
