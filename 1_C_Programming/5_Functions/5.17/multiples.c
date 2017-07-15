#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int multiple(int a, int b)
{
	if( b % a == 0 )
		return 1;
	else
		return 0;
}

int main(int argc, char* argv[])
{
	int a, b;

	while(1)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", multiple(a,b));
	}

	return 0;
}


