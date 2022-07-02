/**
 * @file merge_sorted_array.c
 * @author Ivin Lim (you@domain.com)
 * 
 * @brief merge two non-decreasing sorted arrays arr1 and arr2 into one descending array2 with arr1 variable being merged onto
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/* Standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief 
 * 
 * @param nums1 one of two arrays to be merged with
 * @param nums1Size size of nums1 array
 * @param m 
 * @param nums2 
 * @param nums2Size 
 * @param n 
 */


/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    nums1Size=m+n;
    nums1Size=n;
    int p1,p2,i;
    p1=m-1,p2=n-1,i=m+n-1;
    //1. from nums2 number of elements to 0
    while(p2>=0)
    {
        //2. check each arrays values starting from their ends; unless we've reached end of nums1
        if(p1>=0 && nums1[p1]>=nums2[p2])
        {
            //3. if greater, swap element in nums1 to near end of whole array
            nums1[i]=nums1[p1];
            i--;
            p1--;
        }
        else
        {
            //if we've reached end of nums1 for comparison or value in nums2 was bigger
            // we instead swap current index in nums2 to end of whole array
            nums1[i]=nums2[p2];
            i--;
            p2--;
        }
    }
}

int main(int argc, char* argv[])
{
    int nums1Size = 6;
    int nums2Size = 3;
    int m = 3; // number of elements in nums1 to be included
    int n = 3; // number of elements in nums2 to be included
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};

    
	printf("nums1 is \n");
    printArray(nums1, nums1Size);
	printf("nums2 is \n");
    printArray(nums2, nums2Size);


    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    printf("merged nums1 is \n");
    printArray(nums1, nums1Size);

    return 0;
}
