#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ctr = 0;
	int acctNumber;
	double iniLimit;
	double newLimit;
	double balance;

	while ( ctr < 3 )
	{
		printf("Account Number: ");
		scanf("%d", &acctNumber);
		printf("Initial Limit: ");
		scanf("%lf", &iniLimit);
		printf("Current Balance: ");
		scanf("%lf", &balance);

		newLimit = iniLimit / 2;
		printf("New limit is %lf\n", newLimit);
		if( newLimit <= balance  )
			printf("warning, customer %d has exceeded their new credit card limit.\n", acctNumber);

		ctr++;		
	}
		

	return 0;
}
