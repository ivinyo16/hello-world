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


int uniquePaths(int m, int n) {
    int* arr = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = (m == 1) ? 1 : i+1;
        DEBUG_PRINT("arr[%d] = %d\n", i, arr[i]);
    }
    if (m > 2) {
        m -= 2;
        while (m > 0) {
            for (int i = 1; i < n; i++) {
                arr[i] += arr[i-1];
            }
            m--;
        }
    }
    int ans = arr[n-1];
    free(arr);
    return ans;
}

int main(int argc, char* argv[])
{
    int m = 4 , n = 4;
    DEBUG_PRINT("INT_MAX: %d\n", INT_MAX);

    printf("unique paths: %d\n", uniquePaths(m,n));

    return 0;
}
