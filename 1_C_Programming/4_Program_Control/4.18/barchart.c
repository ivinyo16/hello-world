#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ctr = 0, ctr2 = 0;;
	int input;

	while ( ctr < 5)
	{
		printf("Enter a number: ");
		scanf("%d", &input);
		for( ctr2 = 0; ctr2 < input ; ctr2++)
		{
			printf("*");
		}	
		printf("\n");	
		ctr2 = 0;
		ctr++;
	}
	

	return 0;
}
