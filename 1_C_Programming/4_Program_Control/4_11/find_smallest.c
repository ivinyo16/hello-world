#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<stdbool.h>

int main(int argc, char* argv[])
{
	int num=0, x=0, small, ctr=0;
	bool flag_set=false;
	printf("Enter number of numbers: ");
	scanf("%d", &num);
	for( ctr = 0 ; ctr < num ; ctr++ )
	{
		printf("Enter new number: ");
		scanf("%d", &x);
                if( !flag_set && !small )
		{
                        small = x;
			flag_set = true;
		}
		if( x < small )
			small = x;
	}
	printf("the smallest number is %d\n", small);
	

	return 0;
}
