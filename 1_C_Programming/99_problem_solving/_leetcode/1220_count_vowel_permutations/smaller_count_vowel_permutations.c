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

    long int a = 1, e = 1, i = 1, o = 1, u = 1;
    long int a_new, e_new, i_new, o_new, u_new;

    for(int j = 1; j < n ; j++ )
    {
        //ex. number of a's found due to the number of e's,i's, and u's from previous iteration
        DEBUG_PRINT("a %d\n", a);
        DEBUG_PRINT("e %d\n", e);
        DEBUG_PRINT("i %d\n", i);
        DEBUG_PRINT("o %d\n", o);
        DEBUG_PRINT("u %d\n\n", u);
        a_new = (e + i + u) % MOD;
        e_new = (a + i ) % MOD;
        i_new = (e + o ) % MOD;
        o_new = (i ) % MOD;
        u_new = (i + o) % MOD;
        a = a_new;
        e = e_new;
        i = i_new;
        o = o_new;
        u = u_new;
        DEBUG_PRINT("a %d\n", a);
        DEBUG_PRINT("e %d\n", e);
        DEBUG_PRINT("i %d\n", i);
        DEBUG_PRINT("o %d\n", o);
        DEBUG_PRINT("u %d\n", u);

    }

    int ans = (a + e + i + o + u) % MOD;

    return ans;
}

int main(int argc, char* argv[])
{
    int n = 50;
    printf("number of valid %d-character strings: %d\n", n, countVowelPermutation(n));

    return 0;
}
