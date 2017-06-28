#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ctr, num, num2;
	//first
	for ( ctr = 1 ; ctr <= 10; ctr++ )
	{
		num = 0;
		do
		{
			printf("*");
			num++;
		}
		while( num < ctr);
		printf("\n");
	}
	printf("\n");
	//second
	for ( ctr = 10 ; ctr >=1 ; ctr--)
	{
		
		num = 0;
		do
		{
			printf("*");
			num++;
		}
		while( num < ctr );
		printf("\n");
	}
	//third
	for ( ctr = 10; ctr >= 1 ; ctr--)
	{
	        num = 0;
                num2 = 10;
                do
                {
                        printf(" ");
                        num2--;
                }
                while( num2 >= ctr);

                do
                {
                        printf("*");
                        num++;
                }
                while( num < ctr );
                printf("\n");
	}
	//fourth
        for ( ctr = 1 ; ctr <= 10; ctr++ )
        {
                num = 0;
                num2 = 10;
                do
                {
                        printf(" ");
                        num2--;
                }
                while( num2 >= ctr);

                do
                {
                        printf("*");
                        num++;
                }
                while( num < ctr);
                printf("\n");
        }
        printf("\n");

	

	return 0;
}
