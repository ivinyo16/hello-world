#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <uthash.h>

#define MAX_NUM 8


typedef struct {
	int num;
	int idx;
	// Makes structure hashable
	UT_hash_handle hh;
} num_t;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int* res = calloc((*returnSize = 2), sizeof(int));
	num_t *numsHash = NULL, *num = NULL, *tmp = NULL;

	for(int i = 0; i < numsSize; ++i){
		int toFind = target - nums[i];
		HASH_FIND_INT(numsHash, &toFind, num);

		if (num != NULL){
			res[0] = num->idx;
			res[1] = i;

			break;
		} else {
			num = malloc(sizeof(num_t));
			num->num = nums[i]; num->idx = i;

			HASH_ADD_INT(numsHash, num, num);
		}
	}

	HASH_ITER(hh, numsHash, num, tmp) {
		HASH_DEL(numsHash, num); free(num); 
	}

	return res;
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
