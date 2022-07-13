/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief 
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* arrayCreate(int n){
    int* newArray=(int*)malloc(n*sizeof(int));
    newArray[0]=1;
    newArray[n-1]=1;
    return newArray;
}
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int ** T=(int**)malloc(numRows*(sizeof(int*)));
    int i,j;
    for(i=0;i<numRows;i++)
        T[i]=arrayCreate(1+i);
    for(i=2; i<numRows;i++)
        for(j=1; j<i;j++)
            T[i][j]=T[i-1][j-1]+T[i-1][j];
    *returnSize=numRows;
    *returnColumnSizes=arrayCreate(numRows);
    for(i=0;i<numRows;i++)
        (*returnColumnSizes)[i]=i+1;
    return T;
}

void printMatrix(int *row_size, int **column_size, int **matrix)
{
    int i,j;
    for( i = 0 ; i < *row_size ; i++ )
    {
        for( j = 0 ; j < (*column_size)[i] ; j++ )
        {
            printf("%d, ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, char* argv[])
{
    int return_row_size = 0;
    int* return_column_sizes;
    int **return_array = NULL;
    int idx = 0;

    //our variable input
    int numRows = 5;
    return_array = generate( numRows, &return_row_size, &return_column_sizes);

    printMatrix(&return_row_size, &return_column_sizes, return_array);

    if(return_array != NULL)
    {
        for( idx = 0 ; idx < return_row_size ; idx++ )
        {
            free(return_array[idx]);
        }
        free(return_array);
        return_array = NULL;
    }
    free(return_column_sizes);

    return 0;
}
