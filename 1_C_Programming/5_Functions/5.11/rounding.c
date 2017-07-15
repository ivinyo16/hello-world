#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double roundToInteger(double number)
{
	return floor ( number + 0.5);		
}

double roundToTenths(double number)
{
	return floor( number * 10 + .5 ) / 10;
}

double roundToHundreths(double number)
{
	return floor( number * 100 + .5 ) / 100;
}

double roundToThousandths(double number)
{
	return floor( number * 1000 + .5 ) / 1000;
}


int main(int argc, char* argv[])
{
	double number;

	printf("Enter a numer: ");
	scanf("%lf", &number);
	printf("Nearest Integer: %f\n", roundToInteger(number));
	printf("Nearest Tenths: %f\n", roundToTenths(number));
	printf("Nearest Hundreths: %f\n", roundToHundreths(number));
	printf("Nearest Thousandths: %f\n", roundToThousandths(number));

	return 0;
}
