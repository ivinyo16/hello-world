#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ctr = 1;
	int temp=0;
	unsigned int binary = 0;
	int num = 1;
	printf("%4s%8s%10s%14s\n", "Decimal", "Binary", "Octal", "Hexadecimal");	
	while( ctr < 256 )
	{
		printf("%4d", ctr);
		printf("   ");
		temp = ctr;
		while( temp >= num*2)
		{
			num *= 2;
		}
		while(num)
		{
			if(temp & num)
			 	printf("1");
			else
				printf("0");
			num >>= 1;
		}
		printf("%10o%14x\n", ctr, ctr);
		ctr++;
		num = 1;
	}	

	return 0;
}
