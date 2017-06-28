#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	float e=1;
	unsigned int ctr=1, power=1, pwrctr=1, facto=1, x=0;
	x = atoi(argv[1]);
	while(1)
	{
		power*=x;
		facto*=ctr;
		ctr++;		
		e+= (float) power/facto;
		printf("%d\n", power);
		printf("%d\n", facto);
		printf("e^%d = %f\n", x,e);
		sleep(2);	
	}

	return 0;
}

		

	


