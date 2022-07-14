/**
 * @file matrix_chain_order.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 *  Find the least amount of scalar multiplication that we can do given to a matrix from i to j
 * ex.
 *  (A1*A2)*A3 has m scalar multiplications needed
 *  (A1)*(A2*A3) has n scalar multiplications needed
 *  in this case n < m, therefore we want to return n.
 * 
 * Bonus:
 * Print out the parenthesisization that shows the least amount of multiplcations needed such as the one above
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
#include <limits.h>

int matrixChainOrder(int matrix[][2], int size, int first_array, int last_array)
{

    int n = size - 1;
    //m[i][j] holds the value with least amount of matrix scalar mult needed from matrix Ai to Aj
    int m[n][n];
    int s[n][n];
    int i = 0;
    int l = 0;
    int j = 0;
    int k = 0;
    int q = 0;

    //one matrix = no multiplication operation done
    for ( i = 0 ; i < size ; i++ )
    {
        m[i][i] = 0;
    }

    for( l = 1 ; l < size ; l++)
    {
        for( i = 0; i < size-l ; i++ )
        {
            j = i + l ;
            // printf("m[%d,%d]\n", i,j);
            m[i][j] = INT_MAX;
            
            for( k = i ; k < j ; k++)
            {
                // printf("q = m[%d][%d] + m[%d][%d]+ %d*%d*%d\n", i, k, k+1, j, matrix[i][0], matrix[k][1],matrix[j][1]);
                // printf("q = %d + %d + %d*%d*%d\n", m[i][k], m[k+1][j], matrix[i][0], matrix[k][1],matrix[j][1]);
                q = m[i][k] + m[k+1][j] + (matrix[i][0]*matrix[k][1]*matrix[j][1]);
                // printf("q = %d\n", q);
                if(q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[first_array][last_array];
}

int main(int argc, char* argv[])
{
    int matrixes[6][2] = { {30,35}, {35,15}, {15,5}, {5,10}, {10,20}, {20,25} };
    int result = 0;
    result = matrixChainOrder(matrixes, 6, 0, 5);

    printf("least amount of scalar multiplication that can be done is %d\n", result);

    return 0;
}
