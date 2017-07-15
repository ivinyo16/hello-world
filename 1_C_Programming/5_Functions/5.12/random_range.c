#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int ctr;

	for (ctr = 0; ctr < 10; ctr++)
	{
		// where -3 <= n <= 11
		printf("%d\n", (rand()%15) -3);
	}
	

	return 0;
}
