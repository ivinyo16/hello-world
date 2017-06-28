#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int x=0, power=0, i=0, y = 0;
	scanf("%d", &x);
	scanf("%d", &power);
	
	y = x;
	i++;
	while( i < power )
	{
		y = x * y;
		i++;
	}

	printf("\n power is %d\n", y);





}
