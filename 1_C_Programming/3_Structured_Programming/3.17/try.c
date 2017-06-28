#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

int miles=0, totalmile=0;
float gal=0,rate, total=0, totalgal=0;

while ( gal != -1 )
{
	printf("Enter gallons: ");
	scanf("%f", &gal);
	if( gal == -1)
		break;
	printf("Enter miles: ");
	scanf("%d", &miles);
	rate =  miles/gal;
	printf("the rate for this trip is: %f\n", rate);
	totalmile += miles;
	totalgal += gal;
}
total = totalmile/totalgal;
printf("\n The total rate is: %f\n", total);

















}
