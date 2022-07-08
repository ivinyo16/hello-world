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

int cutRod(int price_array[], int total_length)
{
    int max_price = -1;
    int current_price = 0;
    int idx = 0;
    int length_idx = total_length - 1;
    if(total_length == 0)
    {
        return 0;
    }

    for (idx = 0 ; idx < total_length; idx++)
    {
        current_price = price_array[idx] + cutRod(price_array, total_length-1-idx);
        if(current_price > max_price)
        {
            max_price = current_price;
        }
        // current_price = 0;
    }

    return max_price;
}

int main(int argc, char* argv[])
{
    // int price_table_vs_inch[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int price_table_vs_inch[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 32, 35, 38, 39, 40, 47, 47, 50, 54, 60, 32, 35, 38, 39, 40, 47, 47, 50, 54, 60 };
    int size = sizeof(price_table_vs_inch)/sizeof(int);

    int idx = 0;
    int max = 0;
    int current_sell;
    int best_length;
    for ( idx = size ; idx > 0 ; idx-- )
    {
        current_sell = cutRod(price_table_vs_inch , idx);
        if(current_sell > max)
        {
            max = current_sell;
            best_length = idx;
        }
    }
    printf("best length to sell rod at total %d inches with revenue of %d\n", best_length, max);

    return 0;
}
