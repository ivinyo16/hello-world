#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int current=0, second=0, first=0, ctr=0;
	for(ctr=0; ctr<10; ctr++)
	{
		printf("Enter a number: ");
		scanf("%d", &current);
		if(current > first)
		{
			second = first;
			first = current;
		}
		else if(current > second)
			second = current;
		
	}
	printf("First largest number: %d\n", first);
	printf("Second largest number: %d\n", second);









}
