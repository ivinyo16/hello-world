#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void squareShape(int size)
{
	int ctr, ctr2;
	for ( ctr = 0 ; ctr < size ; ctr++)
	{
		for( ctr2 = 0; ctr2 < size; ctr2++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	int size;
	scanf("%d", &size);
	squareShape(size);	
	

	return 0;
}
