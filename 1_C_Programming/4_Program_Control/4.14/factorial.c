#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int unsigned factorial = 1;
	int end = 5;
	printf("  Number     Value\n");
	for ( int ctr = 1; ctr <= end ; ctr++ )
	{
		factorial *= ctr;
		printf("    %d           %d\n", ctr, factorial);
	}
	return 0;
}
