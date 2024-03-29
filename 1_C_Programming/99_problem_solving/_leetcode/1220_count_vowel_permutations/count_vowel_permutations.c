/**
 * @file count_vowel_permutations.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
 * 
 * Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
 * Each vowel 'a' may only be followed by an 'e'.
 * Each vowel 'e' may only be followed by an 'a' or an 'i'.
 * Each vowel 'i' may not be followed by another 'i'.
 * Each vowel 'o' may only be followed by an 'i' or a 'u'.
 * Each vowel 'u' may only be followed by an 'a'.
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: n = 1
 * Output: 5
 * Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
 * Example 2:
 * 
 * Input: n = 2
 * Output: 10
 * Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
 * Example 3: 
 * 
 * Input: n = 5
 * Output: 68
 * 
 * techniques used:
 * - dynamic programming
 * 
 * @version 0.1
 * @date 2022-08-06
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

#define MOD      1000000007

/**
 * @brief 
 * a = 0 
 * e = 1
 * i = 2
 * o = 3
 * u = 4
 * 
 */


int countVowelPermutation(int n)
{   
    DEBUG_PRINT("%d\n", MOD);
    /**
     * @brief dp[number of vowels][nth size string +1 index offset]
     * each row represents number of times vowel 'row' has spawned at nth round
     *
     */
    long int dp[5][n+1];
    memset( dp, 0, sizeof(dp) );

    dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] =dp[4][1] = 1; 


    for(int i = 2; i < n+1 ; i++ )
    {
        //ex. number of a's found due to the number of e's,i's, and u's from previous iteration
        dp[0][i] = (dp[1][i-1] + dp[2][i-1] + dp[4][i-1]) % MOD;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1] ) % MOD;
        dp[2][i] = (dp[1][i-1] + dp[3][i-1] ) % MOD;
        dp[3][i] = (dp[2][i-1] ) % MOD;
        dp[4][i] = (dp[2][i-1] + dp[3][i-1]) % MOD;
    }

    int ans = 0;

    for(int i = 0 ; i < 5 ; i++ )
    {
        ans = (ans+ dp[i][n]) % MOD;
    }

    return ans;
}

int main(int argc, char* argv[])
{
    int n = 40;
    printf("number of valid %d-character strings: %d\n", n, countVowelPermutation(n));

    return 0;
}
