#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int x=0;
	x = atoi(argv[1]);
	if( (x/10000)%10 == x%10  && (x/1000)%10 == (x/10)%10)
		printf("Yes, this is a palindrome\n");
		

	
	return 0;
}
