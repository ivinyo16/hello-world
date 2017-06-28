#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int x=0, power=1, digit,decimal=0, ctr=0;
	x = atoi(argv[1]);
	for(ctr=0; ctr<50; ctr++)
	{
		digit = x%10;
		decimal+=digit*power;
		x/=10;
		power*=2;
	}
	printf("decimal is: %d\n", decimal);
		

	
	return 0;
}
