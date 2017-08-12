#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Status {FULL, ONGOING};

int getch()
{
	int c;
	system("/bin/stty raw");
	c = getchar();
	system("/bin/stty cooked");
	return c;
}

int checkSeats(const int seats[], int class)
{
	int ctr;
	if(class == '1')
	{
		for( ctr = 1 ; ctr <= 5 ; ctr++ )
		{
			if (seats[ctr] == 0)
				return ctr;
		}
	}
	else if (class == '2')
	{
		for( ctr = 6 ; ctr <= 10 ; ctr++ )
		{
			if (seats[ctr] == 0)
				return ctr;
		}		
	}
	return 0;
}

int bookSeat( int seats[], int seatnum)
{
	if(!seatnum)
		return 0;
	seats[seatnum] = 1;
	printf("\nseat number: %d\n", seatnum);
	if(seatnum < 6)
		printf("business class\n");
	else
		printf("economy\n");
	return 1;
}


int main(int argc, char* argv[])
{
	int seats[11] = {0};
	int userInput;
	enum Status bookStatus = ONGOING;

	while(bookStatus == ONGOING)
	{
		printf("Please type 1 for \"first class\"\n");
		printf("Please type 2 for \"economy\"\n");
		userInput = getch();
		if(!bookSeat(seats,checkSeats(seats, userInput)))
		{
			if(userInput == '1')
				printf("\nno more seats available in business. Would you like economy(y/n)?\n");
			else
				printf("\nno more seats available in economy. Would you like business(y/n)?\n");
			if(getch()=='y')
			{
				userInput = userInput=='1' ? '2' : '1';		//try other class
				if(!bookSeat(seats,checkSeats(seats, userInput)))
					bookStatus = FULL;
			}	
		

		}

	}

	printf("\n Next flight in 3 hours.\n");
	system("/bin/stty cooked");
	return 0;
}
