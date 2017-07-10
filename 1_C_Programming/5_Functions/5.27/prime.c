#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPrime(int number)
{
	int ctr;
	for( ctr = 2; ctr < number ; ctr++)
	{
		if(number % ctr == 0)
			return 0;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	int num;
	//scanf("%d", &num);

	for(num = 1; num <= 100; num++)
	{
		if(isPrime(num))
			printf("%d\n", num);
	}

	return 0;
}
