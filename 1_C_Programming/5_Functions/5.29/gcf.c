#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gcf(int a, int b)
{
	int ctr = 1;
	int small, gcf = 1;
	//determine smaller number
	if ( a < b )
		small = a;
	else
		small = b;
	for( ctr == 1; ctr <= small ; ctr++)
	{
		if( (a % ctr == 0) && ( b % ctr == 0))
			gcf = ctr;
	}
	return gcf;

}

int main(int argc, char* argv[])
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", gcf(a,b));
	

	return 0;
}
