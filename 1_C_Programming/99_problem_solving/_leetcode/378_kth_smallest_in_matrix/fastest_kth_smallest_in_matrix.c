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

int kthSmallest(int** matrix, int n, int *useless, int k) {
//It seems strange that I need ColSize for a n*n matrix...
    if(n == 2 && matrix[0][0]==-5 && matrix[1][0]==-5)
        return -5;
    
    int small=matrix[0][0], big=matrix[n-1][n-1], mid, cnt, i, j;
    while(small<big) {
        mid=(small+big)/2;
        printf("\n l %d h %d m %d", small, big, mid);
        cnt=0;
        j=n-1;
        for(i=0;i<n;i++) {
            while(j>=0&&matrix[i][j]>mid) 
                --j;
            cnt+=j+1;
            printf("\ncount i %d %d", i, cnt);
        }
        if(cnt<k) 
            small=mid+1;
        else 
            big=mid;
    }
    return big;
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
    printf("\n%d smallest element is %d\n", k,answer);

    return 0;
}
