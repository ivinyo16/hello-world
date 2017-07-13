#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int isPrime(int number)
{
	int ctr;
	for( ctr = 2; ctr <= sqrt(number) ; ctr++)
	//for( ctr = 2; ctr <= number/2; ctr++)
	{
		if(number % ctr == 0)
			return 0;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	int num;
	clock_t begin, end;
	double time_spent;
	int limit = 100000;

	begin = clock();

	for(num = 1; num <= limit ; num++)
	{
		if(isPrime(num))
			printf("%d\n", num);
	}
	end = clock();
	time_spent = (double) (end-begin) / CLOCKS_PER_SEC ;
	printf("cpu time: %f\n", time_spent);
	return 0;
}
