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

#include "header.h"

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{

    // [1,3,50] [2,14,16,100]
    int mid_index = (nums1Size + nums2Size ) / 2;
    double result;
    int total_elements = nums1Size + nums2Size;

    int num1_idx = 0, num2_idx = 0;
    int m1 = 0, m2 = 0;
    int gone_thru_elements = 0 ;


    while( gone_thru_elements <= mid_index)
    {
        m2 = m1;
        if( num1_idx !=  nums1Size && num2_idx !=  nums2Size )
        {
            if ( nums1[num1_idx] < nums2[num2_idx])
            {
                m1 = nums1[num1_idx++];
            }
            else if (nums1[num1_idx] > nums2[num2_idx])
            {
                m1 = nums2[num2_idx++];
            }
            else
            {
                m1 = nums1[num1_idx++];
                num2_idx++;
                gone_thru_elements++;
            }
        }
        else if ( num1_idx < nums1Size)
        {
            m1 = nums1[num1_idx++];
        }
        else
        {
            m1 = nums2[num2_idx++];
        }
        gone_thru_elements++;
        printf("%d - %d \n", gone_thru_elements, m1);
    }
    //if odd
    if ( (total_elements % 2) == 1 )
    {
        result = (double) m1;
    }
    else
    {
        result = ( (double) (m1 + m2) ) / 2.0;
    }

    return result;


}