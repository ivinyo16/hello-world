#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int integerQuotient(int a, int b)
{
	return a / b;
}

integerRemainder(int a, int b)
{
	return a % b;
}

int main(int argc, char* argv[])
{
	short quotient;
	int divisor = 10000;
	scanf("%d", &quotient);
	do
	{
		if(quotient != integerRemainder(quotient,divisor))		//prevent preceeding zeroes	
			printf("%d  ", integerQuotient(quotient, divisor));
		quotient = integerRemainder(quotient, divisor); //new quotient
		//printf("\n%d remainder", quotient);
		divisor /= 10;
	}
	while(quotient > 1);
	printf("\n");
	return 0;
}
