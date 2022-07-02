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

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void mergeCombine(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        mergeCombine(arr, l, m, r);
    }
}

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
    //1. merge first our two arrays into nums1
    int idx;
    for( idx = m ; idx < m+n ; idx++ )
    {
        nums1[idx] = nums2[idx-m]; 
    }
    mergeSort(nums1, 0, m+n-1);
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
