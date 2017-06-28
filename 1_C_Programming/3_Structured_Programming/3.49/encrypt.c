#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned int x = 0, a = 0, b = 0,  c = 0, d = 0, encrypt = 0;
	x = atoi(argv[1]);
	a = (((x / 1000) % 10) + 7) % 10;
	b = (((x / 100) % 10) + 7) % 10 ;
	c = (((x / 10) % 10) + 7) % 10;
	d = ((x % 10) + 7) % 10;
	encrypt = c * 1000 + d * 100 + a * 10 + b;
	printf("encrypted: %d\n", encrypt);
	return 0;
}







		

	


