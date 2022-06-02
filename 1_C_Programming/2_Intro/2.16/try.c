#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int a, b;
	printf("please enter value for a:");
	scanf("%d", &a);
	printf("please enter value for b:");
	scanf("%d", &b);
	printf("\nsum is %d\n", a + b);
	printf("difference is %d\n", a - b);
	printf("product is %d\n", a * b);
	printf("quotient is %d\n", a / b);
	printf("remainder is %d\n", a % b);
	printf("the difference of b to a  is %d\n", b - a);
}
