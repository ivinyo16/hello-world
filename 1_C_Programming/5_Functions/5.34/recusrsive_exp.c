#include <stdio.h>
#include <string.h>
#include <stdlib.h>

power(int base, int exponent)
{
	if(exponent > 0)
		return base * power(base, exponent - 1);
	else
		return 1;

}

int main(int argc, char* argv[])
{
	int base, exponent;
	scanf("%d %d", &base, &exponent);

	printf("%d\n", power(base,exponent));
	

	return 0;
}
