#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int cointoss()
{
	
	return (rand() % 2);
}

int main(int argc, char* argv[])
{
	int ctr, headcount=0, tailcount=0;
	srand(time(NULL));
	for(ctr = 0 ; ctr < 100; ctr++)
	{
//		printf("%d\n", cointoss());
		if(cointoss())
			headcount++;
		else
			tailcount++;
	 }
	printf("%d heads, %d tails\n", headcount, tailcount);
	

	return 0;
}
