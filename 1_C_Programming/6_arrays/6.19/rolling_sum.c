#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define REPEAT 36000
#define SIZE 13

int sumOfRoll()
{
	//printf("%d\n", rand()%6+1);
	return ((rand()%6)+1 + (rand()%6)+1);
}
int main(int argc, char* argv[])
{
	int sums[SIZE] = {0};
	int i = 0;
	srand(time(NULL));
	for( i = 0 ; i < REPEAT ; i++)
		++sums[sumOfRoll()];
	for(i = 2 ; i < SIZE ; i++)
		printf("%4d%12d\n", i, sums[i]);

	return 0;
}
