#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibonacci(int n)
{
	int ctr, fibo = 1, prev = 0;
	if( n == 0)
		return 0;
	else if (n == 1 )
		return 1;
	for ( ctr = 2 ; ctr < n; ctr++)
	{
		prev = fibo - prev; //  1  1  2  3
		fibo += prev;       //  2  3  5  8
	}
	return fibo;
}
	
int main(int argc, char* argv[])
{
	int num;
	scanf("%d", &num);
	printf("%d\n", fibonacci(num));
	

	return 0;
}
// 0 1 2 3 4 5 6
// 0 1 1 2 3 5 8