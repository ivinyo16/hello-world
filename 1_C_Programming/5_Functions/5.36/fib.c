#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibo(int n)
{
	if(n==1 || n==0)
		return 1;
	else
		return fibo(n-1) + fibo(n-2);

}

int main(int argc, char* argv[])
{
	int n;
	scanf("%d", &n);

	printf("%d\n", fibo(n));
	

	return 0;
}