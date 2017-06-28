#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned int x = 0, a = 0, b = 0,  c = 0, d = 0, decrypt = 0;
	x = atoi(argv[1]);
	c = (((x / 1000) % 10) + 3) % 10;
	d = (((x / 100) % 10) + 3) % 10;
	a = (((x / 10) % 10) + 3) % 10;
	b = ((x % 10) + 3) % 10;
	decrypt = a * 1000 + b * 100 + c * 10 + d;
	printf("encrypted: %d\n", decrypt);
	return 0;
}







		

	


