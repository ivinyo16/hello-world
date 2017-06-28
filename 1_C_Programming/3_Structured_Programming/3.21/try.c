#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int hours=0, rate=0;
	float total=0;
	while( hours != -1)
	{
		printf("Enter number of hours worked: ");
		scanf("%d", &hours);
		if(hours==-1)
			break;
		printf("Enter salary: ");
		scanf("%d", &rate);
		if( hours > 40 )
			total = (float) (rate*40)+(hours-40)*(rate*1.5);
		else
			total = (float) rate*hours;
		printf("Salary is: %f\n", total);
	}
}
