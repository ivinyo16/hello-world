/**
 * @file kth_smallest_in_matrix.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * 
 * You must find a solution with a memory complexity better than O(n2).
 * 
 * techniques used:
 * - heapsort
 * - matrix
 * 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

// #define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

#define SWAP(x,y) {int t; t = x; x = y; y = t;}

int getParent(int key)
{
    return ( (key-1)/2 );
}

int getLeftChild(int key)
{
    return ((2*key) + 1);
}

int getRightChild(int key)
{
    return ((2*key) + 2);
}

void topDown_heapify(int *arr, int tail, int index)
{
    DEBUG_PRINT("topDown_heapify at index %d\n", index);
    int left = getLeftChild(index);
    int right = getRightChild(index);
    int largest = index; //index of largest value

    //check if left is bigger
    if( left <= tail && arr[left] > arr[index])
    {
        largest = left;
    }

    // DEBUG_PRINT("right compare [%d]%d _____  [%d]%d\n", right, arr[right]->key, largest, arr[largest]->key);
    if( right <= tail && arr[right] > arr[largest])
    {
        largest = right;
    }

    
    //check if we need switching and further checking
    if(largest != index)
    {
        DEBUG_PRINT("^switch\n");
        //swap
        SWAP(arr[largest], arr[index]);
    

        topDown_heapify(arr, tail, largest);
    }
}

void buildMaxHeap(int *arr, int size)
{
    int tail = size - 1;
    int no_leaf_end_index  = (tail - 1) / 2;
    DEBUG_PRINT("no_leaf_end_index %d\n", no_leaf_end_index);
    for(int i = no_leaf_end_index ; i >= 0 ; i--)
    {
        topDown_heapify(arr, tail, i);
    }
}

void heapSort(int *arr, int size)
{
    buildMaxHeap(arr, size);
    int tail = size - 1;
    int last = tail;
    for ( int i = tail ; i >= 0 ; i-- )
    {
        SWAP(arr[0], arr[i]);
        topDown_heapify(arr, --last, 0);

    }
}

void printMatrix(int m, int n, int **matrix)
{
    int i,j;
    for( i = 0 ; i < m ; i++ )
    {
        for( j = 0 ; j < n ; j++ )
        {
            printf("%d, ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printArray(int n, int  *arr)
{
    for( int j = 0 ; j < n ; j++ )
    {
        printf("%d, ", arr[j]);
    }
    printf("\n");
}


int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    // printf("%d\n");
    int size = matrixSize * *matrixColSize;
    int arr[size];
    for(int i = 0 ; i  < size; i++ )
    {
        arr[i] = matrix[i/matrixSize][i%matrixSize];
    }
    printArray(size, arr);
    heapSort(arr, size);
    printArray(size, arr);
    

    return arr[k-1];
}

int main(int argc, char* argv[])
{
    int **mat;
    int m;
    int n = m = 3;
    int k = 4;  //kth smallest number in the matrix
    mat = (int**)malloc( sizeof(int*) * m);
    int idx = 0;
    for( idx = 0 ; idx < m ; idx++ )
    {
        mat[idx] = (int*)malloc(sizeof(int)*n);
    }
    int mat_size = m;
    int mat_col_size = n;
    int answer = 0;

    //populate
    srand(time(NULL));
    for( int i = 0 ; i < m ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            mat[i][j] = (rand() % 100)+ j*100;
        }
    }

    printMatrix(mat_size, mat_col_size,mat);


    answer = kthSmallest(mat, mat_size, &mat_col_size, k);
    printf("%d smallest element is %d\n", k,answer);

    return 0;
}
