/* Fig. 5.10: fig05_10.c
Craps */
#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* contains prototype for function time */
/* enumeration constants represent game status */
enum Status { CONTINUE, WON, LOST };
int rollDice( void ); /* function prototype */

#define GAMESPLAYED 1000
#define ROUNDSCOPE 21

int main( void )
{
	int sum, ctr, rounds; 
	int myPoint; 
	enum Status gameStatus; 
	srand( time( NULL ) );
	int rollsNeededWin[ROUNDSCOPE] = {0};
	int rollsNeededLose[ROUNDSCOPE] = {0};
	for( ctr = 0; ctr < GAMESPLAYED; ctr++)
	{
		sum = rollDice(); 
		switch( sum ) 
		{
			case 7:
			case 11:
				gameStatus = WON;
				++rollsNeededWin[1];
				break;
			case 2:
			case 3:
			case 12:
				gameStatus = LOST;
				++rollsNeededLose[1];
			break;
			default:
				gameStatus = CONTINUE;
				myPoint = sum;
				printf( "Point is %d\n", myPoint );
			break; /* optional */
		}
		rounds = 2;
		while ( gameStatus == CONTINUE ) 
		{
			sum = rollDice(); 
			if ( sum == myPoint ) 
			{ 
				gameStatus = WON; 
				if(rounds < ROUNDSCOPE)
					rollsNeededWin[rounds]++;
			} 
			else
		 	{
				if ( sum == 7 ) 
				{
					gameStatus = LOST;
					if(rounds < ROUNDSCOPE)
						rollsNeededLose[rounds]++;
				} 
			} 
			rounds++;
		} 
		if ( gameStatus == WON ) 
		{ 
			printf( "Player wins\n" );
		} 
		else 
		{ 
			printf( "Player loses\n" );
		} 
	}
	for( ctr = 1; ctr < ROUNDSCOPE; ctr++)
	{
		printf("%4d%10d\n", ctr, rollsNeededWin[ctr]);
	}
	for( ctr = 1; ctr < ROUNDSCOPE; ctr++)
	{
		printf("%4d%10d\n", ctr, rollsNeededLose[ctr]);
	}
	return 0;
} 

int rollDice( void )
{
	int die1; 
	int die2; 
	int workSum;
	die1 = 1 + ( rand() % 6 ); 
	die2 = 1 + ( rand() % 6 ); 
	workSum = die1 + die2; 
	printf( "Player rolled %d + %d = %d\n", die1, die2, workSum );
	return workSum; /* return sum of dice */
} /* end function rollRice */