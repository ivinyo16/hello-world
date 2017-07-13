#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum Status { CONTINUE, SUCCESS, OVER };

void clearinputbuffer()
{
	while(getchar() == EOF)
	{

	}
}

int main(int argc, char* argv[])
{
	char response;
	int choosen, guess;
	enum Status gameStatus = CONTINUE;

	srand(time(NULL));
	choosen = rand() % 10;

	while( gameStatus == CONTINUE)
	{
		scanf("%d", &guess);
		//guess = getchar();
		if( guess == choosen)
		{
			printf("Excellent!\n");
			gameStatus = SUCCESS;
		}
		else if( guess < choosen)
			printf("Too low\n");
		else if( guess > choosen)
			printf("Too high\n");
		printf("Try again? (y/n): ");

		clearinputbuffer();			
			switch(getchar()) 
			{
			case 'n' :
				gameStatus = OVER;
				break;
			case 'y' :
				if(gameStatus == SUCCESS)
				{
					srand(time(NULL));
					choosen = rand() % 10;
				}
				gameStatus = CONTINUE;
				break;
			default :
				printf("invalid\n");
			}
		
	}

	

	return 0;
}
