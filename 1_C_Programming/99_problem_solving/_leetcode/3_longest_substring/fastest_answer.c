#include <stdio.h>
#include <string.h>
#include <stdlib.h>




struct node {
        struct node *greater;
        struct node *less;
        int last_index;
        char c;
};

/*
 *  add a character from a string to a binary tree
 *  if character not found in tree, return -1
 *  otherwise return the previous index of the character
 */
int add_node(struct node *head, char c, int index)
{
        struct node **target = &head;
        printf("\nenter add_node\n");

        while (*target) {
                if (c < (*target)->c)
                {
                        printf("LESS c: %c  (*target)->c: %c\n", c,  (*target)->c);
                        target = &(*target)->less;
                }
                else if (c > (*target)->c)
                {
                        printf("GREATER c: %c  (*target)->c: %c\n", c,  (*target)->c);
                        target = &(*target)->greater;
                }
                else
                {
                        printf("BREAK c: %c  (*target)->c: %c\n", c,  (*target)->c);
                        break;
                }
        }

        if (*target) { /* match found */
                int tmp = (*target)->last_index;
                (*target)->last_index = index;
                printf(" match found index: %d\n", index);
                return tmp; 
        }

        /* match not found */
        *target = calloc(1, sizeof(struct node));
        (*target)->c = c;
        (*target)->last_index = index;
        printf("nope - index: %d\n", index);
        return -1;
}

int lengthOfLongestSubstring(char *s)
{
        struct node head;
        memset(&head, 0, sizeof(head));

        int longest = 0; /* the record for the longest substring without repeating chars */
        int repeat = -1; /* index of last repeated character (the second-last instance) */

        char c;
        int i = 0;
        while ((c = *(s + i))) {
                int r = add_node(&head, c, i);

                if (r >= 0) { /* character seen before */
                        if (r > repeat)
                                repeat = r;
                }

                int streak;
                if (repeat < 0) /* no repeated chars yet */
                        streak = i + 1;
                else
                        streak = i - repeat;

                if (streak > longest)
                        longest = streak;

                i++;
        }
                
        return longest;
}

int main()
{

    // char sample[] = "anviaj";
    char sample[] = "abcabcbb";
    int answer = 0;
    answer = lengthOfLongestSubstring(sample);


    printf("\nanswer: %d\n", answer);
    return 0;
}