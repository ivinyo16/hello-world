/**
 * @file search_2d_matrix.c
 * @author your name (you@domain.com)
 * @brief 
 * Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * 
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
#include <stdbool.h>
#include <time.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int m = matrixSize;
    int n = *matrixColSize;

    //an m*n matrix  m can be represented in an array
    //m[x][y] --> a[x*n+y]

    //vice versa
    //a[x] --> m[x/n][x%n]

    //use endices
    int end = m*n-1;
    int start = 0;

    while(start <= end)
    {
        //we start at the middle
        int mid = start + (end - start)/2;

        //check at a[mid]
        if( target == matrix[mid/n][mid%n] )
        {
            return true;
        }
        else if( target > matrix[mid/n][mid%n] )
        {
            start = mid + 1;
        }
        else if( target < matrix[mid/n][mid%n] )
        {
            end = mid - 1;
        }
    }

    return false;
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
    int m = 4;
    int n = 3;
    int mat_size = m;
    int mat_col_size = n;
    int target = 50;
    bool answer = false;
    mat = (int**)malloc( sizeof(int*) * m);
    int idx = 0;
    for( idx = 0 ; idx < m ; idx++ )
    {
        mat[idx] = (int*)malloc(sizeof(int)*n);
    }

    //populate with increasing values
    srand(time(NULL));
    for( int i = 0 ; i < m ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            if(j == 0 && i == 0)
            {
                mat[i][j] = (rand() % 10)+1;
            }
            else if(j == 0 && i != 0)
            {
                mat[i][j] = ((rand() % 10)+1)+ mat[i-1][n-1];
            }
            else
            {
                mat[i][j] = ((rand() % 10)+1)+ mat[i][j-1];
            }

        }
    }

    printMatrix(mat_size, mat_col_size,mat);
    answer = searchMatrix(mat, mat_size, &mat_col_size, target);

    printf("is %d in matrix: %s\n", target, answer ? "true" : "false");


    //free
    if(mat != NULL)
    {
        for( idx = 0 ; idx < m ; idx++ )
        {
            free(mat[idx]);
        }
        free(mat);
        mat = NULL;
    }


    return 0;
}
