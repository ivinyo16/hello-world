#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	float a,b,c, smallest;
	scanf("%f %f %f", &a, &b, &c);
	printf("%f %f %f\n", a, b, c);

	//assume a is smallest
	smallest  = a;
	if(smallest > b)
		smallest = b;
	if (smallest > c)
		smallest = c;

	printf("smallest is %f\n", smallest);

	

	

	return 0;
}
