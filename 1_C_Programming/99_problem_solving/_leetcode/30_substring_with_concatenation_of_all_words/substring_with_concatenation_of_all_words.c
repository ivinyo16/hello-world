/**
 * @file substring_with_concatenation_of_all_words.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) 
 * in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
 * 
 * You can return the answer in any order.
 * 
 * Example 1:
 * 
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * Example 2:
 * 
 * Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * Output: []
 * Example 3:
 * 
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * Output: [6,9,12]
 *  
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 104
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * s and words[i] consist of lowercase English letters.
 * 
 * Techniques used:
 * - hash table
 * 
 * @version 0.1
 * @date 2022-08-13
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

#define TABLE_SIZE 26

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize)
{
    int words_hash[TABLE_SIZE] = {0};
    int s_hash[TABLE_SIZE] = {0};
    int sizes_per_word[wordsSize];
    int total_size_of_words = 0;
    int total_size_of_s = 0;
    int smallest_word_step = INT_MAX;
    char *current = NULL;
    bool is_found = false;
    bool are_word_present = true;
    int *indexes = NULL;

    for (int i = 0; i < wordsSize ; i++)
    {
        sizes_per_word[i] = 0;
        current = words[i];
        while(*current != '\0')
        {
            words_hash[*current - 'a']++;
            current++;
            sizes_per_word[i]++;
        }
        total_size_of_words +=  sizes_per_word[i];
        if(sizes_per_word[i] < smallest_word_step)
        {
            smallest_word_step = sizes_per_word[i];
        }
    }

    current = s;
    while( *current != '\0' )
    {
        total_size_of_s++;
        current++;
    }

    
    DEBUG_PRINT("sizes_per_word %d\n", sizes_per_word[0]);
    DEBUG_PRINT("total_size_of_words %d\n", total_size_of_words);
    DEBUG_PRINT("total_size_of_s %d\n", total_size_of_s);
    DEBUG_PRINT("sssssss %d\n", total_size_of_s - total_size_of_words);
    for(int i = 0; i <= total_size_of_s - total_size_of_words ; i++ )
    {
        // DEBUG_PRINT("number of i %d\n", i);
        memset(s_hash,0, TABLE_SIZE*sizeof(int));
        for(int j = i ; j < total_size_of_words + i ; j++ )
        {
            s_hash[s[j] - 'a']++;
        }
        // DEBUG_PRINT("number of a %d\n", s_hash[0]);

        //check as a whole to even consider doing next level checking
        if(memcmp(s_hash,words_hash, TABLE_SIZE) == 0)
        {
            //check order of words each
            are_word_present = true;
            for (int k = 0; k < wordsSize ; k++)
            {
                // DEBUG_PRINT("WORD %s\n", words[k]);
                
                //check each substring step
                is_found = false;
                // DEBUG_PRINT("number of i %d\n", i);
                for(int j = i; j < i + total_size_of_words ; j+=smallest_word_step )
                {
                    // DEBUG_PRINT("check %s\n", &s[j]);
                    // DEBUG_PRINT("number of e %d\n", s_hash['e'-'a']);
                    // DEBUG_PRINT("number of wordse %d\n", words_hash['e'-'a']);
                    // DEBUG_PRINT(" j %d\n", j);
                    if( memcmp(&s[j],words[k],smallest_word_step) == 0)
                    {
                        is_found = true;
                        continue;
                    }
                }
                if(!is_found)
                {
                    are_word_present = false;
                    continue;
                }
            }
            if(are_word_present)
            {
                (*returnSize)++;
                if(!indexes)
                {
                    indexes = (int *) malloc(sizeof(int));
                    indexes[(*returnSize)-1] = i;
                }
                else
                {
                    indexes = (int *)realloc(indexes, sizeof(int) * *returnSize);
                    indexes[(*returnSize)-1] = i;
                }
            }
        }
    }

    return indexes;
}

int main(int argc, char* argv[])
{
    char *s = "barfoothefoobaraaaaaaaa";
    int *answer = NULL;
    // char **words = (char *[]){"foo","bar"};
    char *words[] = { "foo", "bar" };
    int wordsSize = sizeof(words)/sizeof(words[0]);
    int returnSize = 0;

    answer = findSubstring(s, words, wordsSize, &returnSize);
    printf("return size: %d\n", returnSize);
    for (int i = 0 ; i < returnSize ; i++ )
    {
        printf("%d ", answer[i]);
    }
    free(answer);

    return 0;
}
