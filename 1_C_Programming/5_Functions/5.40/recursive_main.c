#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	static int x = 1;
	x++;
	printf("%d\n", x);
	main();

	

	return 0;
}
