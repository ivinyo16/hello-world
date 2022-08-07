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

#define MAX_NUMBER      1000000007

/**
 * @brief 
 * a = 0 
 * e = 1
 * i = 2
 * o = 3
 * u = 4
 * 
 */
//                     a    e        i         o     u      start
int mapping[6][5] = { {1}, {0,2}, {0,1,3,4}, {2,4}, {0}, {0,1,2,3,4} };
int map_size_per_index[6] = {1,2,4,2,1,5};

int countVowelPermutationAux(int n, int hash[], int map_index)
{
    if(n == 0)
    {
        return 1;
    }
    if(map_index == 5)
    {
        countVowelPermutationAux(n-1, hash, 0);
        countVowelPermutationAux(n-1, hash, 1);
        countVowelPermutationAux(n-1, hash, 2);
        countVowelPermutationAux(n-1, hash, 3);
        countVowelPermutationAux(n-1, hash, 4);
        
    }

    if(map_index == 0)
    {
        hash[map_index] += map_size_per_index[map_index] - 1;
        DEBUG_PRINT("hash[%d] = %d\n", map_index, hash[map_index]);
        countVowelPermutationAux(n-1, hash, 1);
    }
    if(map_index == 1)
    {
        hash[map_index] += map_size_per_index[map_index] - 1;
        DEBUG_PRINT("hash[%d] = %d\n", map_index, hash[map_index]);
        countVowelPermutationAux(n-1, hash, 0);
        countVowelPermutationAux(n-1, hash, 2);
    }
    if(map_index == 2)
    {
        hash[map_index] += map_size_per_index[map_index] - 1;
        DEBUG_PRINT("hash[%d] = %d\n", map_index, hash[map_index]);
        countVowelPermutationAux(n-1, hash, 0);
        countVowelPermutationAux(n-1, hash, 1);
        countVowelPermutationAux(n-1, hash, 3);
        countVowelPermutationAux(n-1, hash, 4);
    }
    if(map_index == 3)
    {
        hash[map_index] += map_size_per_index[map_index] - 1;
        DEBUG_PRINT("hash[%d] = %d\n", map_index, hash[map_index]);
        countVowelPermutationAux(n-1, hash, 2);
        countVowelPermutationAux(n-1, hash, 4);
    }
    if(map_index == 4)
    {
        hash[map_index] += map_size_per_index[map_index] - 1;
        DEBUG_PRINT("hash[%d] = %d\n", map_index, hash[map_index]);
        countVowelPermutationAux(n-1, hash, 0);
    }
    return 1;
}

int countVowelPermutation(int n)
{   
    int hash[] = {1,1,1,1,1};
    int ans = 0;
    countVowelPermutationAux( n , hash, 5);
    for( int i = 0 ; i < 5 ; i++ )
    {
        ans += hash[i] % MAX_NUMBER;
    }
    return ans;
}

int main(int argc, char* argv[])
{
    int n = 10;
    printf("number of valid %d-character strings: %d\n", n, countVowelPermutation(n));

    return 0;
}
