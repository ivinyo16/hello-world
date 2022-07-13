/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief  You are given an m x n matrix mat and two integers 
 *      r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
 *      The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
 *      If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
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
#include <time.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    if(matSize*(*matColSize)!=r*c)
    {
        *returnSize=matSize;
        *returnColumnSizes=matColSize;
        return mat;
    }
    
    *returnSize=r;
    *returnColumnSizes=malloc(sizeof(int)*(*returnSize));
    int **ret=malloc(sizeof(int*)*r);
    
    for(int i=0;i<(*returnSize);i++)
    {       
        ret[i]=malloc(sizeof(int)*c);
        (*returnColumnSizes)[i]=c;
    }

    
    for(int i=0;i<(*returnSize);i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i*c+j==matSize*matColSize[0])return ret;
            ret[i][j]=mat[(i*c+j)/matColSize[0]][(i*c+j)%matColSize[0]];
        }
    }

    return ret;
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
    int **returned_array = NULL;
    // int mat[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};
    int **mat;
    int m = 4;
    int n = 3;
    int r = 6;  // desired new row
    int c = 2; //desired column
    mat = (int**)malloc( sizeof(int*) * m);
    int idx = 0;
    for( idx = 0 ; idx < m ; idx++ )
    {
        mat[idx] = (int*)malloc(sizeof(int)*n);
    }
    int mat_size = m;
    int mat_col_size = n;

    //populate
    srand(time(NULL));
    for( int i = 0 ; i < m ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            mat[i][j] = rand() % 1000;
        }
    }

    int return_size = 0;
    int *return_column_size;

    printMatrix(mat_size, mat_col_size,mat);

    returned_array = matrixReshape( mat, mat_size, &mat_col_size, r, c, &return_size, &return_column_size);

    printMatrix(return_size, *return_column_size,returned_array);

    if(returned_array != NULL)
    {
        for( idx = 0 ; idx < return_size ; idx++ )
        {
            free(returned_array[idx]);
        }
        free(returned_array);
        returned_array = NULL;
    }
    if(mat != NULL)
    {
        for( idx = 0 ; idx < m ; idx++ )
        {
            free(mat[idx]);
        }
        free(mat);
        mat = NULL;
    }
    free(return_column_size);
    return 0;
}
