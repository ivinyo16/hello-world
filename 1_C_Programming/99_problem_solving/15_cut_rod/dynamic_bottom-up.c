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

int bottomsUpCutRod(int price_array[] , int size)
{
    size++;
    int hash[size];
    hash[0] = 0;
    int idx = 0, idx2;
    int max = 0;
    int current = 0;
    static int count = 0;
    for(idx = 1 ; idx < size; idx++)
    {
        max = INT_MIN;
        for(idx2 = 0; idx2 < idx ; idx2++)
        {
            current = price_array[idx2] + hash[idx-idx2-1];
            printf("count = %d\n", count++);
            if(current > max)
            {
                max = current;
            }
        }
        
        hash[idx] = max;
        printf("hash[%d] = %d\n", idx, hash[idx]);

    }

    return hash[size-1];
}

int main(int argc, char* argv[])
{
    // int price_table_vs_inch[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int price_table_vs_inch[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 32, 35, 38, 39, 40, 47, 47, 50, 54, 60, 32, 35, 38, 39, 40, 47, 47, 50, 54, 60 };
    int size = sizeof(price_table_vs_inch)/sizeof(int);

    int current_sell;
    int best_length;

    current_sell = bottomsUpCutRod(price_table_vs_inch , size);

    printf("best length to sell rod at total %d inches is with revenue of %d\n", size, current_sell);

    return 0;
}
