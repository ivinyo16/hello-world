#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 8


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *answer;
    //int j;
    int i, eclass;
    int diff;
    int hash_size;
    int mask;
    
    struct Node 
    {
        int index;
        struct Node* next;
    };
    
    struct Head
    {
        struct Node *start;
        struct Node *end;
    };
    
    struct Head *hashtable;
    struct Node *temp = NULL;
    struct Node *membuf;
    struct Node *memptr;
    int *numsptr, *numstart;
    
    answer = malloc(2 * sizeof(int));
    
    hash_size = 1 << (31 - __builtin_clz(numsSize));
    mask = hash_size - 1;
    hashtable = calloc(hash_size, sizeof(struct Head));
    memptr = membuf = malloc(numsSize * sizeof(struct Node));
    
    //initialize hash table
    
    for(numstart = numsptr = &nums[0]; numsptr < &nums[numsSize]; numsptr++)
    {
        eclass = *numsptr & mask;
        if (hashtable[eclass].start == NULL)
        {
            hashtable[eclass].end = hashtable[eclass].start = memptr++;
        }
        else
        {
            hashtable[eclass].end = hashtable[eclass].end->next = memptr++;
        }
        hashtable[eclass].end->index = (int) (numsptr - numstart); // index = i
        hashtable[eclass].end->next = NULL;
    }
    
    //look for target sums
    for (i=0; i<numsSize; i++)
    {
        diff = target - nums[i];
        eclass = diff & mask;
        // check each item in bucket
        temp = hashtable[eclass].start;

        while(temp != NULL) 
        {
            if (temp->index != i && nums[temp->index] == diff)
            {
                //match
                goto finish;
            }
                temp = temp->next;
        }  
    }

finish:
    answer[0] = i;
    answer[1] = temp->index;
    free(membuf);
    free(hashtable);
    
    * returnSize = 2;
    return answer;
}
int main(int argc, char* argv[])
{
    int numsSize = MAX_NUM;
    int nums[MAX_NUM] = {3,2,4,1,9,6,3,8};
    int target = 9;
    int returnSize;
    int *yes;
    yes = twoSum( nums, numsSize, target, &returnSize);
    if(yes == NULL)
    {
        printf("nothing found\n");
        return -1;
    }
    printf("main yes[0] %d\n", yes[0]);
    printf("main yes[1] %d\n", yes[1]);
    free(yes);

    return 0;
}
