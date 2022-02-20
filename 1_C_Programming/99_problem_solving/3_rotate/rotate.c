#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rotate(int *nums, int numsSize, int k)
{
    int temp[numsSize];
    for(int i = 0 ; i < numsSize ; i++)
    {
        temp[i] = nums[i];
    }

    for(int i = 0 ; i < numsSize ; i++)
    {
        if(i-k < 0)
        {
            nums[i] = temp[(numsSize-(k-i))];
        }
        else
        {
            nums[i] = temp[i-k];
        }
    }
}


int main(int argc, char* argv[])
{

    int numsSize = 7;
    int nums[7] = {1,2,3,4,5,6,7};
    int k = 4;
    
    rotate(nums, numsSize, k);
    for (int i = 0 ; i < numsSize ; i++)
    {
        printf("%d ", nums[i]);
    }


	return 0;
}
