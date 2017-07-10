#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int perfect (int number)
{
	int ctr, sum = 0;
	for( ctr = 1;  ctr < number; ctr ++)
	{
		if(number % ctr == 0)
			sum += ctr;
	}
	if(sum == number)
		return 1;
	else
		return 0;
}

int main(int argc, char* argv[])
{
	int num;
//	scanf("%d", &num);
	for( num = 1 ; num <= 1000 ; num++)
	{
		if(perfect(num))
			printf("%d\n", num);
	}

	return 0;
}
