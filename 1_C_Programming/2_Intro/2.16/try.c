#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("\nsum is %d\n", a + b);
	printf("difference is %d\n", a - b);
	printf("product is %d\n", a * b);
	printf("quotient is %d\n", a / b);
	printf("remainder is %d\n", a % b);
}
