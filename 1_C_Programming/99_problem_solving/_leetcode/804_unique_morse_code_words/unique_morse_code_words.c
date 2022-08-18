/**
 * @file unique_morse_code_words.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * For convenience, the full table for the 26 letters of the English alphabet is given below:
 * 
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
 * "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * 
 * Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
 * 
 * For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
 * Return the number of different transformations among all words we have.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: words = ["gin","zen","gig","msg"]
 * Output: 2
 * Explanation: The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * There are 2 different transformations: "--...-." and "--...--.".
 * Example 2:
 * 
 * Input: words = ["a"]
 * Output: 1
 *  
 * 
 * Constraints:
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 12
 * words[i] consists of lowercase English letters.
 * 
 * Techniques used:
 * - hash table
 * - qsorting
 * 
 * @version 0.1
 * @date 2022-08-16
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

int cmpfunc (const void * a, const void * b) {
    char *pa = ((char *) a);
    char *pb = (char *) b;
    // DEBUG_PRINT("pa %s\n", pa);
    // DEBUG_PRINT("pb %s\n\n", pb);
    // DEBUG_PRINT("%d\n", strcmp(pa,pb));
    return(strcmp(pa,pb));
}

int uniqueMorseRepresentations(char ** words, int wordsSize)
{
    char *morse_map[26] = 
    {
        ".-",       // a
        "-...",     // b
        "-.-.",     // c
        "-..",      // d
        ".",        // e
        "..-.",     // f
        "--.",      // g
        "....",     // h
        "..",       // i
        ".---",     // j
        "-.-",      // k
        ".-..",     // l
        "--",       // m
        "-.",       // n
        "---",      // o
        ".--.",     // p
        "--.-",     // q
        ".-.",      // r
        "...",      // s
        "-",        // t
        "..-",      // u
        "...-",     // v
        ".--",      // w
        "-..-",     // x
        "-.--",     // y
        "--..",     // z
    };

    if(wordsSize == 1)
    {
        return 1;
    }
    int answer = wordsSize;

    char transformed_words[wordsSize][50];

    for(int i = 0 ; i < wordsSize ; i++ )
    {
        int len = strlen(words[i]);
        char *cur = words[i];
        strcpy(transformed_words[i], "");
        while( *cur != '\0' )
        {
            strcat(transformed_words[i], morse_map[*cur - 'a']);
            // DEBUG_PRINT("index %s\n", transformed_words[i]);
            cur++;
        }
        DEBUG_PRINT("transformed: %s\n", transformed_words[i]);
    }
    qsort(transformed_words, wordsSize, sizeof(transformed_words[0]), cmpfunc);
    for(int i = 0 ; i < wordsSize ; i++ )
    {
        DEBUG_PRINT("new: %s\n", transformed_words[i]);
    }

    for(int i = 1 ; i < wordsSize ; i++ )
    {
        if(strcmp(transformed_words[i-1],transformed_words[i]) == 0)
        {
            answer--;
        }
    }
    return answer;



}

int main(int argc, char* argv[])
{
    char *words[] = {"gin", "zen", "gig", "msg"};
    int size = sizeof(words)/sizeof(words[0]);
    DEBUG_PRINT("wordssize %d\n", size);
    int answer = 0;
    answer = uniqueMorseRepresentations(words, size);
    printf("answer: %d\n", answer);

    return 0;
}
