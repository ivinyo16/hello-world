/**
 * @file best_time_buy_sell.c
 * @author your name (you@domain.com)
 * @brief You are given an array prices where prices[i] is the price of a given stock on the ith day.
 *  
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize)
{
    int i = 0, j = 0, k = 0; //indexes
    int ultimate_max = INT_MIN;
    int current_max = 0;
    int profit = 0;
    int hash[pricesSize];

    for( i = 0 ; i < pricesSize ; i++ )
    {
        hash[i] = INT_MIN;
    }

    for( i = 0 ; i < pricesSize ; i++ )
    {
        //find largest profit on ith day
        current_max = INT_MIN;
        profit = INT_MIN;
        for( j = 1+i ; j < pricesSize ; j++ )
        {
            profit = prices[j] - prices[i];
            // printf("%d - %d\n", prices[j], prices[i]);
            if( profit > current_max )
            {
                current_max = profit;
            }
        }
        //save largest profit
        hash[i] = current_max;
        // printf("hash[%d] = %d\n", i, hash[i]);

        if(current_max > ultimate_max)
        {
            ultimate_max = current_max;
        }

        
    }
    if(ultimate_max < 0 )
    {
        return 0;
    }
    else
    {
        return ultimate_max;
    }
}


int main(int argc, char* argv[])
{
    // int stocks[] = {7,1,5,3,6,4};
    int stocks[] = {7,6,4,3,1};
    // int stocks[] = {1,2,3,4,5};
    // int stocks[] = {5,4,3,2,1};
    int size = sizeof(stocks)/sizeof(int);

    int max_profit = maxProfit(stocks, size);

    printf("max profit that can be achieved at %d\n", max_profit);

    return 0;
}
