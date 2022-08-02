/**
 * @file unique_paths.c
 * @author your name (you@domain.com)
 * @brief 
 * There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
 * 
 * Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 *
 * techniques used:
 *  - dynamic programming
 *  - memoization
 *  - recursion
 * 
 * @version 0.1
 * @date 2022-08-01
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

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

#define MAX_LENGTH 100

int memory_map[MAX_LENGTH][MAX_LENGTH];


int uniquePaths(int m, int n)
{
    int total_paths = 0;

    if(memory_map[m][n] > 0)
    {
        DEBUG_PRINT("memory_map[%d][%d] = %d\n", m,n, memory_map[m][n]);
        return memory_map[m][n];
    }
    
    if(m == 1 || n == 1)
    {
        memory_map[m][n] = 1;
        return 1;
    }

    total_paths = uniquePaths(m-1,n) + uniquePaths(m, n-1);
    memory_map[m][n] = total_paths;

    return total_paths;

}

int main(int argc, char* argv[])
{
    int m = 1 , n = 100;
    DEBUG_PRINT("INT_MAX: %d\n", INT_MAX);

    printf("unique paths: %d\n", uniquePaths(m,n));

    return 0;
}
