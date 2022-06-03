#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 8


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int * values_to_return;
    int hash_map_size = 0;
    int *hash_map = NULL;
    int i = 0;
    int j = 0;
    for( i = 0 ; i < numsSize ; i++ )
    {
        for( j = 0 ; j < hash_map_size; j++ )
        {
            printf("checking %d == %d - %d\n", hash_map[j], target, nums[i]);
            if( hash_map[j] == target - nums[i] )
            {
                printf("target_acquired\n");
                values_to_return = (int*) malloc( 2 * sizeof(int) );
                *returnSize = 2;
                values_to_return[0] = i;
                values_to_return[1] = j;
                free(hash_map);
                return values_to_return;
            }
        }
        hash_map_size++;
        if(hash_map == NULL)
        {
            hash_map = (int*) malloc (hash_map_size * sizeof(int));
        }
        else
        {
            hash_map = (int*) realloc (hash_map, hash_map_size * sizeof(int));
        }
        hash_map[j] = nums[i];
        printf("[j]: %d\n", j);
        printf("hash_map[j]: %d\n", hash_map[j]);
    }
    free(hash_map);
    return values_to_return;
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
