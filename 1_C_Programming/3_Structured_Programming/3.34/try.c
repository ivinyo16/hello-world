#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int x=0, row=0, column=0, flag=0;
	x = atoi(argv[1]);
	if(x <= 0)
		return -1;
	printf("%dx%d hollow\n", x, x);
	for(row=0; row<x; row++)	
	{
		for(column=0; column<x; column++)
		{
			if(column == 0)
				flag = 1;
			if(column == (x-1))
				flag = 1;
			if(row == 0 )
				flag = 1;
			if(row == x-1)
				flag = 1;
			if(flag)
				printf("*");
			else
				printf(" ");
			flag = 0;
		}
		printf("\n");
	}

	return 0;

}
