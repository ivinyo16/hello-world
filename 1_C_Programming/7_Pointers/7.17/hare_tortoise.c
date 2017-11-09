#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum Status {CONTINUE, OVER};

int moveHare(int curPos)
{
	int possibleMove = rand() % 10;
	if(possibleMove <= 1)
		return curPos;
	else if(possibleMove <= 3)
		return curPos + 9;
	else if(possibleMove <= 4)
	{
		if(curPos -12 < 1)
			return 1;
		else
			return curPos - 12;
	}
	else if(possibleMove <= 7)
	{
		return curPos + 1;
	}
	else if(possibleMove <= 9)
	{
		if(curPos -2 < 1)
			return 1;
		else
			return curPos - 2;
	}

}

int moveTortoise(int curPos)
{
	int possibleMove = rand() % 10;
	if(possibleMove <= 4)
		return curPos + 3;
	else if(possibleMove <= 6)
	{
		if(curPos - 6 < 1)
			return 1;
		else
			return curPos - 6;		
	}
	else if(possibleMove <= 9)
		return curPos + 1;

}



int main(int argc, char* argv[])
{
	enum Status raceStatus = CONTINUE;
	int positions[71] = {0};
	int hare = 1;
	int tortoise = 1;

	srand(time(NULL));
	printf("wtf: \n");

	while(raceStatus == CONTINUE)
	{
		printf("%*s\n", hare,"H");
		printf("%*s\n", tortoise,"T");
		if(hare == tortoise)
			printf("%*s\n", hare, "OUCH!");
		if( hare == tortoise == 70)
		{
			printf("draw!\n");
			raceStatus = OVER;
		}
		if(hare >= 70)
		{
			printf("hare wins!\n");
			raceStatus = OVER;
		}
		if (tortoise >= 70)
		{
			printf("tortoise wins!\n");
			raceStatus = OVER;
		}
		sleep(1);
		hare = moveHare(hare);
		tortoise = moveTortoise(tortoise);
		system("clear");
		

	}

	

	return 0;
}
