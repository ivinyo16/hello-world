#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int sum=0, x=0, ctr=-1;
	double aver=0;
	do
	{
		sum += x;
		printf("Enter number: ");
		scanf("%d", &x);
		ctr++;
	}
	while ( x != 9999 );
	printf("sum=%d ctr=%d\n", sum, ctr);
	if(ctr != 0)
		aver = sum / ctr;
	printf("average is %f\n", aver);
	return 0;
}

	



