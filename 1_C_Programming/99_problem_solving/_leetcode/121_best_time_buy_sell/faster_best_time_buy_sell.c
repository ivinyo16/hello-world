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

int maxProfitAux(int *prices, int pricesSize, int hash[])
{
    int i = 0 ;
    int profit = 0;
    int max = INT_MIN;
    int ultimate_max = INT_MIN;

    if(hash[pricesSize-1] >= 0)
    {
        // printf("exist hash[%d] = %d\n", pricesSize-1, hash[pricesSize-1]);
        return hash[pricesSize-1];
    }

    if(pricesSize == 1)
    {
        max = 0;
    }
    else
    {
        i = pricesSize-1;
        // printf("%d: %d - %d + [%d]\n", i, prices[i], prices[i-1], i-1);
        profit = prices[i] - prices[i-1] + maxProfitAux(prices, i, hash);
        // printf("AT %d: %d\n", pricesSize-1, profit);
        if(profit < 0)
        {
            profit = 0;
        }
    }
    hash[pricesSize-1] = profit;
    if(profit > max)
    {
        max = profit;
    }
    // printf("comp hash[%d] = %d\n", pricesSize-1, hash[pricesSize-1]);

    return max;
}

int maxProfit(int* prices, int pricesSize)
{
    int i = 0, j = 0, k = 0; //indexes
    int ultimate_max = INT_MIN;
    int current_max = 0;
    int profit = 0;
    int hash[pricesSize];
    // printf("pricesSize: %d\n", pricesSize);
    for( i = 0 ; i < pricesSize ; i++ )
    {
        hash[i] = INT_MIN;
    }

    // return maxProfitAux(prices, pricesSize, hash);
    for( i = 1 ; i < pricesSize+1 ; i++ )
    {
        profit = maxProfitAux(prices, i, hash);
        if(profit > current_max)
        {
            current_max = profit;
        }
    }
    return current_max;
    return 0;

}


int main(int argc, char* argv[])
{
    // int stocks[] = {7,1,5,3,6,4};
    int stocks[] = {7,1,5,3,6,4};
    // int stocks[] = {7,6,4,3,1};
    // int stocks[] = {1,2,3,4,5};
    // int stocks[] = {5,4,3,2,1};
    int size = sizeof(stocks)/sizeof(int);

    int max_profit = maxProfit(stocks, size);

    printf("max profit that can be achieved of profit %d\n", max_profit);

    return 0;
}
