#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
/*
A person invests $1000.00 in a savings account yielding 5% interest. Assuming that
all interest is left on deposit in the account, calculate and print the amount of money
in the account at the end of each year for 10 years. Use the following formula for
determining these amounts:
a = p(1 + r)^n
where
p is the original amount invested (i.e., the principal)
r is the annual interest rate
n is the number of years
a is the amount on deposit at the end of the n th year.
*/
int main(int argc, char* argv[])
{
	double amount;
	double principal = 1000.0;
	double rate = 0.05;
	int year;

	for( int ctr = 0; ctr < 5 ; ctr++)
	{
	
		printf( "%4s%21s\n", "Year", "Amount on deposit" );
	
		for ( year = 1; year <= 10; year++ ) 
		{
			amount = principal * pow( 1.0 + rate, year );
			printf( "%4d%21.2f\n", year, amount );
		}	
		rate = rate + 0.01;
		printf("rate is now %.2f %\n", rate*100);
	}	
	return 0;
}
