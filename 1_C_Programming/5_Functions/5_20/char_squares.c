#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void squareShape(int size, char symbol)
{
	int ctr, ctr2;
	for ( ctr = 0 ; ctr < size ; ctr++)
	{
		for( ctr2 = 0; ctr2 < size; ctr2++)
		{
			printf("%c", symbol);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	int size;
	char symbol;
	scanf("%d %c", &size, &symbol);
	squareShape(size, symbol);	
	

	return 0;
}
