#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int qualitypoints(int average)
{
	if( average >= 90 )
		return 4;
	if ( average >= 80)
		return 3;
	if ( average >= 70)
		return 2;
	if (average >= 60)
		return 1;
	else
		return 0;
}

int main(int argc, char* argv[])
{
	int average;
	scanf("%d", &average);
	printf("%d\n", qualitypoints(average));

	return 0;
}
