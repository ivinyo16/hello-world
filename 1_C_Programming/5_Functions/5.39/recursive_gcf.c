#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcf(int x, int y)
{
	if( y == 0)
		return x;
	else
		return gcf(y, x%y);
}

int main(int argc, char* argv[])
{
	int x,y;
	scanf("%d %d", &x, &y);
	printf("%d\n", gcf(x,y));
	

	return 0;
}
