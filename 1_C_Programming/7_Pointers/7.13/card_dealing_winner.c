/* Fig. 7.24: fig07_24.c
Card shuffling dealing program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/* prototypes */
void shuffle( int wDeck[][ 13 ] );
void deal( const int wDeck[][ 13 ], const char *wFace[],const char *wSuit[] );

void dealHand(  int wDeck[][ 13 ], int playerHand[][13],const char *wFace[], const char *wSuit[] )
{
	static int card = 1; /* card counter */
	int row; /* row counter */
	int column; /* column counter */
	int dealed = card;
//	printf("card: %d\n", dealed);
	for ( card ; card <= dealed + 4; card++ ) 
	{

		for ( row = 0; row <= 3; row++ ) 
		{
			for ( column = 0; column <= 12; column++ ) 
			{
				/* if slot contains current card, display card */
				if ( wDeck[ row ][ column ] == card ) 
				{
					playerHand[row][column] = 1;
					printf( "%5s of %-8s%c", wFace[ column ], wSuit[ row ],card % 2 == 0 ? '\n' : '\t' );
				} 
			} 
		} 
	} 
} 

int checkHand(int wDeck[][13], const char *wFace[], const char *wSuit[] )
{
	int card = 1;
	int row;
	int column;
	int faceCount[13] = {0};
	int suitCount[4] = {0};
	int pairCount = 0;
	bool checkStraight = false; 
	int biggestSuit = 0;
	int points = 0;

	//for ( card = 1; card <= 5; card++ ) 
	//{
		for ( row = 0; row <= 3; row++ ) 
		{
			for ( column = 0; column <= 12; column++ ) 
			{
				if ( wDeck[ row ][ column ] == card ) 
				{
//					printf( "%5s of %-8s%c", wFace[ column ], wSuit[ row ],'\n' );
					if(column > biggestSuit)
						biggestSuit = column;
					faceCount[column]++;
					suitCount[row]++;
				}
			}
		}
	//} 
	for(row = 0; row <= 3; row++)
	{
		if(suitCount[row] == 5)
		{
			printf("\nflush\n");
			points = 18;
		}
	}
	for(column = 0; column <= 12; column++)
	{
		if(column + 4 <= 12)
		{
			if(faceCount[column] && !checkStraight)
			{
				//printf("%d %d %d %d %d\n", faceCount[column], faceCount[column+1], faceCount[column+2], faceCount[column+3], faceCount[column+4]);
				if(faceCount[column+1] && faceCount[column+2] && faceCount[column+3] && faceCount[column+4])
					checkStraight = true;
			}
		}

		switch(faceCount[column])
		{
			case 4:
				printf("\nfour of a kind\n");
				points = 19;
				break;
			case 3:
				printf("\nthree of a kind\n");
				points = 16;
				break;
			case 2:
				pairCount++;
				break;
		}
	}
	if(checkStraight)
	{
		printf("\nStraight\n");
		points = 17;
	}
	if(pairCount == 2)
	{
		printf("\n%d pair(s)\n", pairCount);
		points = 15;
	}
	else if(pairCount == 1)
	{
		printf("\n%d pair(s)\n", pairCount);
		points = 14;
	}
	if(points == 0)
	{
		points = biggestSuit;
	}
//	printf("\npoints: %d\n", points);
	return points;
}

int main( void )
{
	/* initialize suit array */
	const char *suit[ 4 ] = { "Clubs", "Spades", "Hearts", "Diamonds" };
	/* initialize face array */	
	const char *face[ 13 ] =
	{ "Ace", "Deuce", "three", "Four",
	"Five", "Six", "Seven", "Eight",
	"Nine", "Ten", "Jack", "Queen", "King" };
	int deck[ 4 ][ 13 ] = { 0 };
	int player1[4][13] = {0};
	int player2[4][13] = {0};
	int points1 = 0;
	int points2 = 0;

	srand( time( 0 ) ); /* seed random-number generator */

	shuffle( deck ); /* shuffle the deck */

	dealHand(deck, player1, face, suit);
	printf("\nplayer2 turn\n");
	dealHand(deck, player2, face, suit);

	
	points1 = checkHand(player1, face, suit);
	points2 = checkHand(player2, face, suit);
	if(points1 > points2)
		printf("player 1 wins\n");
	else if(points1 < points2)
		printf("player 2 wins\n");
	else 
		printf("draw\n");
	//deal( deck, face, suit ); /* deal the deck */
	//checkHand(deck, face, suit);
	return 0; /* indicates successful termination */
} 	/* end main */

/* shuffle cards in deck */
void shuffle( int wDeck[][ 13 ] )
{
	int row; /* row number */
	int column; /* column number */
	int card; /* counter */
	/* for each of the 52 cards, choose slot of deck randomly */
	for ( card = 1; card <= 52; card++ ) 
	{
	/* choose new random location until unoccupied slot found */
		do 
		{
			row = rand() % 4;
			column = rand() % 13;
		} 
		while( wDeck[ row ][ column ] != 0 ); /* end do...while */
		/* place card number in chosen slot of deck */
		wDeck[ row ][ column ] = card;
	} /* end for */
} /* end function shuffle */

/* deal cards in deck */
void deal( const int wDeck[][ 13 ], const char *wFace[], const char *wSuit[] )
{
	int card; /* card counter */
	int row; /* row counter */
	int column; /* column counter */
	/* deal each of the 52 cards */
	for ( card = 1; card <= 52; card++ ) 
	{
		/* loop through rows of wDeck */
		for ( row = 0; row <= 3; row++ ) 
		{
			/* loop through columns of wDeck for current row */
			/* loop through columns of wDeck for current row */
			for ( column = 0; column <= 12; column++ ) 
			{
				/* if slot contains current card, display card */
				if ( wDeck[ row ][ column ] == card ) 
				{
					printf( "%5s of %-8s%c", wFace[ column ], wSuit[ row ],card % 2 == 0 ? '\n' : '\t' );
				} /* end if */
			} /* end for */
		} /* end for */
	} /* end for */
} /* end function deal */