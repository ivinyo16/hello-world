#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdint.h> //for int8_t
int main(int argc, char* argv[])
{
	unsigned int square = 1;
	int end = 40;
	printf("  Bit     Value\n");
	for ( int ctr = 0; ctr <= end ; ctr++ )
	{
		square *= 2;
		printf("    %d           %u\n", ctr+2, square);
	}
	return 0;
}
