#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void stdprint(int a, int b)
{
	printf("%d --> %d\n", a, b);
}

void hanoi(int disks, int initial, int destination, int temp)
{
	int init = initial, dest = destination, tem =temp;
	int total = pow(2, disks) - 1;
	int ctr = 0;

	if(disks % 2 == 0)
	{
		dest = temp;
		tem = destination;
	}
	for( ctr = 1 ; ctr <= total ; ctr++)
	{
		if( ctr % 3 == 1)
			stdprint(init,dest);
		else if( ctr % 3 == 2)
			stdprint(init,tem);
		else if ( ctr % 3 == 0)
			stdprint(tem, dest);

		
	}	

}

int main(int argc, char* argv[])
{
	int disks, initial, destination, temp;
	scanf("%d %d %d %d", &disks, &initial, &destination, &temp);
	hanoi(disks, initial, destination, temp);

	return 0;
}
