#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int num, ctr, add, sum = 0;
	printf("Enter sequence of integers: ");
	scanf("%d", &num);
	for( ctr = 0 ; ctr < num ; ctr++)
	{
		printf("Enter %d number: ", ctr + 1);
		scanf("%d", &add);
		sum += add;
	}
	printf("total sum is: %d\n", sum);

	return 0;
}

	



