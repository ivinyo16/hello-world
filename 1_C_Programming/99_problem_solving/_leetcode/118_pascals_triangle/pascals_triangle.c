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

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int **our_array = NULL;
    int i=0, j=0;
    
    //0. Increment to start at 1
    *returnSize = numRows;

    //1.allocate rows
    our_array = (int**)malloc(sizeof(int*)*numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int)*numRows);
    //2. allocate columns
    for( i = 0; i < numRows; i++ )
    {
        our_array[i] = (int*)malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i] = i+1;
    }

    //3. populate time
    for( i = 0; i < numRows; i++ )
    {
        for(j = 0 ; j < (*returnColumnSizes)[i] ; j++)
        {
            if(j == 0 || j >= (*returnColumnSizes)[i]-1)
            {
                our_array[i][j] = 1;
                continue;
            }
            our_array[i][j] = our_array[i-1][j-1] + our_array[i-1][j];
        }
    }



    return our_array;
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
