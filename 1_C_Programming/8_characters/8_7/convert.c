#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char **numbers;
	int num[4] = {0};
	long int sum=0;
	char *temp;
	numbers = (char **)malloc(sizeof(char *)*4);
	for(int ctr = 0; ctr < 4 ; ctr++)
	{
//		temp = (char*)&numbers[ctr];
		fgets( (char *) &numbers[ctr],10,stdin);
	}
	for(int ctr = 0; ctr < 4 ; ctr++)
	{
		printf("%s", (char*)&numbers[ctr]);
		num[ctr] = strtol((char *)&numbers[ctr], NULL,0);
		sum += num[ctr];
	}
	printf("sum is %li\n", sum);

	return 0;
}
