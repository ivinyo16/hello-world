#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int product=1, ctr;
	for( ctr = 0 ; ctr <= 15 ; ctr++ )
	{
		if( (ctr % 2) == 1 )
			product *= ctr;
	}
	printf("product is equal to %d\n", product);

	return 0;
}
