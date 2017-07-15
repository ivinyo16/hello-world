#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double hypotenuse(double a, double b)
{
	return sqrt( pow(a, 2) + pow(b, 2) );
}

int main(int argc, char* argv[])
{
	double a, b;
	scanf("%lf %lf", &a, &b);

	printf("%f\n", hypotenuse(a, b));

	return 0;
}
