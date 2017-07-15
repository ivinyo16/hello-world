#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


double calculateCharges(double hours)
{
	double charge;
	if( hours <= 3 )
		return 2;
	else
		charge = 2 + (0.5 * ceil(hours - 3) );

	if(charge >= 10)
		return 10;
	else
		return charge;
}

int main(int argc, char* argv[])
{
	double car1, car2, car3;
	printf("Enter three cars: ");
	scanf("%lf %lf %lf", &car1, &car2, &car3);

	printf("%4s%7s%7s\n", "Car", "Hours", "Charge");
	printf("%4d%7.2f%8.2f\n", 1, car1, calculateCharges(car1));
	printf("%4d%7.2f%8.2f\n", 2, car2, calculateCharges(car2));
	printf("%4d%7.2f%8.2f\n", 3, car3, calculateCharges(car3));
	printf("%2s%7.2f%8.2f\n", "TOTAL", car1+car2+car3, calculateCharges(car3)+calculateCharges(car1)+ calculateCharges(car2));

	

	return 0;
}
