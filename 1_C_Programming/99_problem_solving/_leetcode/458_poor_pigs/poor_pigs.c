/**
 * @file poor_pigs.c
 * @author your name (you@domain.com)
 * @brief 
 * There are buckets buckets of liquid, where exactly one of the buckets is poisonous. To figure out which one is poisonous, 
 * you feed some number of (poor) pigs the liquid to see whether they will die or not. Unfortunately, you only have minutesToTest 
 * minutes to determine which bucket is poisonous.
 * 
 * You can feed the pigs according to these steps:
 * 
 * Choose some live pigs to feed.
 * For each pig, choose which buckets to feed it. The pig will consume all the chosen buckets simultaneously and will take no time.
 * Wait for minutesToDie minutes. You may not feed any other pigs during this time.
 * After minutesToDie minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.
 * Repeat this process until you run out of time.
 * Given buckets, minutesToDie, and minutesToTest, return the minimum number of pigs needed to figure out which bucket is poisonous within the allotted time.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: buckets = 1000, minutesToDie = 15, minutesToTest = 60
 * Output: 5
 * Example 2:
 * 
 * Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
 * Output: 2
 * Example 3:
 *
 *Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
 *Output: 2 
 * 
 * Techniques used:
 * - base number
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
#include <math.h>

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
    int buckets_to_be_checked = buckets-1; // we can leave one bucket unchecked by the pigs. We would know at the end if this is poison or not
    int rounds = minutesToTest / minutesToDie; // this will determine what number base to use.
    /**
     * @brief for example, if we can only do 1 round of testing. We use base 2 in determining how many buckets each pig would need 
     * to check.
     *      ex.
     *      4 - 1 = 3 buckets to check at 1 round       
     *          base 2              1 | 1   4 --> 2 decimal places = at least 2 pigs needed
     * 
     *      1000 - 1 = 999 buckets to check with 15 minutes to wait with total testing time 60 ; t = 4 rounds of testing
     *          base 5              1 | 2 | 4 | 4 | 4 = 999 --> 5 decimal places = at least 5 pigs needed
     *          base 5 cause we don't want no one pig to do 5 or more testing since we only have 4 rounds alloted.
     */

    int base = rounds + 1;
    DEBUG_PRINT("base %d\n", base);
    DEBUG_PRINT("buckets_to_be_checked %d\n", buckets_to_be_checked);

    int number_of_pigs = 0;
    double buckets_being_checked = 0;
    while( buckets_to_be_checked >= buckets_being_checked)
    {
        buckets_being_checked =  pow(base, ++number_of_pigs);
        DEBUG_PRINT("buckets_being_checked %lf\n", buckets_being_checked);
    }

    return number_of_pigs;
}

int main(int argc, char* argv[])
{
    int buckets = 1;
    int toDie = 1;
    int toTest = 1;
    int answer = poorPigs(buckets, toDie, toTest);

    printf("minimum number of pigs: %d\n", answer);

    return 0;
}
