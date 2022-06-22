/**
 * @file find_largest_number.c
 * @author Ivin Lim (ivin.lim16@gmail.com)
 * @brief Finds the largest number whose sum of its digits would equal a target sum. Given also in the input is
 * the number of digits the number would contain
 * @version 0.1
 * @date 2022-06-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int findLargestNumber(int digits, int sum, int *number)
{
    int value[digits];
    int current_sum = 0;
    int j = 0;
    // int final_number = 0;

    //1. initialze array to 9
    int i = 0;
    for( i = 0; i < digits ; i++ )
    {
        value[i] = 9;
    }

    i = 0;
    for( i = 0; i < digits ; i++ )
    {
        current_sum += value[i];
        if(current_sum == sum)
        {
            memset(&value[i+1], 0, sizeof(int)*(digits-i-1));
            for(j = 0 ; j < digits ; j++)
            {
                *number += value[j] * pow(10,digits-j-1);
               
            }
            return 0;
        }
        if((sum - current_sum) <= 9 && i<digits-1)
        {
            value[i+1] = sum-current_sum;
            memset(&value[i+2], 0, sizeof(int)*(digits-i-2));
            for(j = 0 ; j < digits ; j++)
            {
                *number += value[j] * pow(10,digits-j-1);
               
            }
            return 0;
        }
    }
    number = NULL;
    return -1;
}

/* Driver code */
int main()
{
    int digits = 9; //number of digits the number has
    int sum = 79; //target sum the number of digits should attain
    int number=0;


    if(findLargestNumber(digits, sum, &number) == 0)
    {
        printf("number found\n");
        printf("number found: %d\n", number);
    }
    else
    {
        printf("none found\n");
    }

    // free(number);

}
