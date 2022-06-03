#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 5


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int * value_to_return;
    int i, j;
    for ( i = 0 ; i < numsSize -1 ; i++ )
    {
        for ( j = i+1 ; j < numsSize ; j++ )
        {
            if(nums[i] + nums[j] == target)
            {
                value_to_return = (int*) malloc( 2 * sizeof(int) );
                value_to_return[0] = i;
                value_to_return[1] = j;
                *returnSize = 2;
                return value_to_return;

            }
        }
    }
    return value_to_return;
}

int main(int argc, char* argv[])
{
    int numsSize = MAX_NUM;
    int nums[MAX_NUM] = {2, 0, 3, 5, 6};
    int target = 9;
    int returnSize;
    int *value;
    value = twoSum( nums, numsSize, target, &returnSize);
    if(value == NULL)
    {
        printf("nothing found\n");
        return -1;
    }
    printf("main value[0] %d\n", value[0]);
    printf("main value[1] %d\n", value[1]);
    free(value);

    return 0;
}
