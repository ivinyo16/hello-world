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
    int i, j;
    int m, n;
    int numSet;
    for (i = 0; i < boardSize; i++) {
        numSet = 0;
        for (j = 0; j < boardSize; j++) {
            if (board[i][j] == '.') {
                continue;
            } else if ((numSet & (1 << (board[i][j] - '1'))) != 0) {
                return false;
            } else {
                numSet |= 1 << (board[i][j] - '1');
            }
            
        }
    }
    

    for (j = 0; j < boardSize; j++) {
        numSet = 0;
        for (i = 0; i < boardSize; i++) {
            if (board[i][j] == '.') {
                continue;
            } else if ((numSet & (1 << (board[i][j] - '1'))) != 0) {
                return false;
            } else {
                numSet |= 1 << (board[i][j] - '1');
            }
            
        }
    }
    
    for (m = 0; m < boardSize; m += 3) {
        for (n = 0; n < boardSize; n += 3) {
            numSet = 0;
            for (i = m; i < m + 3; i++) {
                for (j = n; j < n + 3; j++) {
                    if (board[i][j] == '.') {
                        continue;
                    } else if ((numSet & (1 << (board[i][j] - '1'))) != 0) {
                        return false;
                    } else {
                        numSet |= 1 << (board[i][j] - '1');
                    }
                    
                }
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
