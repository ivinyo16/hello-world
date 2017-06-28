#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int sum, ctr;
	for( ctr = 0 ; ctr <= 30 ; ctr++ )
	{
		if( (ctr % 2) == 0 )
			sum += ctr;
	}
	printf("sum is equal to %d\n", sum);

	return 0;
}
