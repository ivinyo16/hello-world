#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CATSIZE 9
enum STATUS  {CONTINUE,OVER};


void inputSal( int sal[], int size )
{
	int ctr;
	for ( ctr = 0; ctr < size; ctr++)
	{
		scanf("%d", &sal[ctr]);
	}
}

void outputSal( int sal[], int size)
{
	int ctr;
	printf("%4s%15s\n", "Category", "Number");
	for ( ctr = 0; ctr < size; ctr++)
	{
		if(ctr==size-1)
			printf("%d+%17d\n", 200+(ctr*100), sal[ctr]);
		else
			printf("%d-%d%15d\n", 200+(ctr*100),299+(ctr*100), sal[ctr]);
	}	
}

void addToCategory(int commission, int sal[], int size)
{
	int gross = 0.09*commission + 200;
	printf("salary is %d\n", gross);
	if(gross <= 299)
		++sal[0];
	else if(gross <= 399)
		++sal[1];
	else if(gross <= 499)
		++sal[2];
	else if(gross <= 599)
		++sal[3];
	else if(gross <= 699)
		++sal[4];
	else if(gross <= 799)
		++sal[5];
	else if(gross <= 899)
		++sal[6];
	else if(gross <= 999)
		++sal[7];
	else if(gross > 1000)
		++sal[8];
	
}

int main(int argc, char* argv[])
{
	int commission = 0;
	int salaryGroup[CATSIZE] = {0};
	enum STATUS status = CONTINUE;
	while (status == CONTINUE)
	{
		if(!scanf("%d", &commission))
			break;
		addToCategory(commission, salaryGroup, CATSIZE);

	}
	outputSal(salaryGroup, CATSIZE);



	

	return 0;
}
