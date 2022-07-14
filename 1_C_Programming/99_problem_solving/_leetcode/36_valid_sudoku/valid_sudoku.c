/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 *      
 *      Each row must contain the digits 1-9 without repetition.
 *      Each column must contain the digits 1-9 without repetition.
 *      Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *      Note:
 *      
 *      A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 *      Only the filled cells need to be validated according to the mentioned rules.
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

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{

    char hm_of_rows[9][9];
    char hm_of_columns[9][9];
    char hm_of_squares[9][9];
    int i = 0, j = 0;
    int num = 0;

    memset(hm_of_rows, '0', sizeof(hm_of_rows[0][0]) * 9 * 9); 
    memset(hm_of_columns, '0', sizeof(hm_of_columns[0][0]) * 9 * 9); 
    memset(hm_of_squares, '0', sizeof(hm_of_squares[0][0]) * 9 * 9); 

    // for( i = 0; i < 9 ; i++)
    // {
    //     memset(hm_of_rows[i], '0', 9);
    //     memset(hm_of_columns[i], '0', 9);
        
    //     memset(hm_of_squares[i], '0', 9);
    // }

    // printf("sss %d\n", hm_of_rows[1][2]);

    for( i = 0; i < 9 ; i++)
    {
       for( j = 0; j < 9 ; j++)
       {
            //skip if current is blanked
            if( board[i][j] == '.')
            {
                continue;
            }
            printf("i %d j %d\n", i,j);

            //change to char
            num = (board[i][j]-1)-'0';
            printf("num: %d\n", num+1);
            


            // check rows
            if( hm_of_rows[i][num] == '0')
            {
                printf("row ok %c\n", hm_of_rows[i][num]);
                hm_of_rows[i][num] = '1';
            }
            else 
            {
                printf("HIT row %u\n",  i);
                return false;
            }
            
            // check columns
            if( hm_of_columns[num][j] == '0')
            {
                printf("column ok at %d\n", j);
                hm_of_columns[num][j] = '1';
            }
            else 
            {
                printf("HIT column %u\n",  j);
                return false;
            }

            //check boxes
            if( hm_of_squares[(i%9-i%3+j/3)][num] == '0')
            {
                printf("box ok\n");
                hm_of_squares[(i%9-i%3+j/3)][num] = '1';
            }
            else
            {
                printf("HIT box %d\n", (i%9-i%3+j/3) );
                return false;
            }
       }
    }

    return true;
}

void printMatrix(int *row_size, int *column_size, char **matrix)
{
    int i,j;
    for( i = 0 ; i < *row_size ; i++ )
    {
        for( j = 0 ; j < *column_size ; j++ )
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    char **board;
    int boardSize = 9;
    int boardColSize = 9;
    int random;
    bool the_truth = false;
    
    srand(time(NULL));

    //initialize rows
    board = (char**)malloc(sizeof(char*)*9);
    for( int i = 0 ; i < 9 ; i++ )
    {
        board[i] = (char*)malloc(sizeof(char)*9);
        for(int j = 0 ; j < 9 ; j++ )
        {
            random = rand() % 50;
            if(random < 10 && random != 0)
            {
                board[i][j] = random+'0';
            }
            else
            {
                board[i][j] = '.';
            }
        }
    }

    printMatrix(&boardSize, &boardColSize, board);

    the_truth = isValidSudoku(board, boardSize, &boardColSize);

    printf("\nValid: %s\n", the_truth ? "true" : "false");

    for( int i = 0 ; i < 9 ; i++ )
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
