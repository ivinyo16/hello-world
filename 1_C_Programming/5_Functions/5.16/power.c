#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int integerPower(int base,int exponent)
{
	int power = 1;
	for( int ctr = 0; ctr < exponent; ctr++)
	{
		power *= base;
	}
	return power;
}

int main(int argc, char* argv[])
{
	int base, exponent;
	scanf("%d %d", &base, &exponent);

	printf("%d\n", integerPower(base,exponent));
	

	return 0;
}
