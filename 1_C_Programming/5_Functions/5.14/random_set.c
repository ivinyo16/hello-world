#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int ctr;

	for (ctr = 0; ctr < 15; ctr++)
	{
		// where set of 2,4,6,8
		//printf("%d\n", (rand()%4 + 1) * 2);
		// 3,5,7,9,11
		//printf("%d\n", ((rand()%5 + 1) * 2) + 1);
		//6,10,14,18,22
		printf("%d\n", ((rand()%5 + 1) * 4) + 2);
	}
	

	return 0;
}
