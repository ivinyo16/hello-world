#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int x = 1;
	int *n = &x;
	*n = 2;
	printf("%d\n", *n);

	char *s = "this is an array";
	int count;
	for(; *s != '\0'; s++)
		printf("%c\n",*s);
	

	return 0;
}
