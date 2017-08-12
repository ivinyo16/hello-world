#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLOORSIZE 50

enum Status {CONTINUE, OVER};
enum Orientation {UP, RIGHT, DOWN, LEFT};
int x = 0, y = 0;

void cleanBuffer()
{
    int n;
    while((n = getchar()) != EOF && n != '\n' );
}

void printFloor(int floor[][FLOORSIZE])
{
	system("clear");
	int i,j;
	for( i = 0; i < FLOORSIZE ; i++)
	{
		for(j = 0; j < FLOORSIZE ; j++)
			printf("%4d", floor[i][j]);
		printf("\n");
	}


}

int move(int floor[][FLOORSIZE], int steps, int orientation, bool penDown)
{
	int ctr;

	if(orientation == LEFT || orientation == UP)
		steps = -1*steps;

	//check it doesn't overstep bounds
	if(orientation == LEFT || orientation == RIGHT)
	{
		if( x + steps < 0 || x + steps >= FLOORSIZE )
			return 0;
	}
	if(orientation == UP || orientation == DOWN)
	{
		if( y + steps < 0 || y + steps >= FLOORSIZE)
			return 0;
	}

	if(!penDown)
	{
		if(orientation == LEFT || orientation == RIGHT)
			x += steps;
		if(orientation == UP || orientation == DOWN)
			y += steps;
	}
	else
	{
		if(orientation == RIGHT)
		{
			for( ctr = x; ctr <= x+steps; ctr++)
			{
				floor[y][ctr] = 1;
			}
			x += steps;
		}
		if(orientation == LEFT)
		{
			for( ctr = x; ctr >= x+steps; ctr--)
			{
				floor[y][ctr] = 1;
			}
			x += steps;
		}

		if(orientation == DOWN)
		{
			for( ctr = y; ctr <= y+steps; ctr++)
			{
				floor[ctr][x] = 1;
			}
			y += steps;
		}
		if(orientation == UP)
		{
			for( ctr = y; ctr >= y+steps; ctr--)
			{
				floor[ctr][x] = 1;
			}
			y += steps;
		}
	}


	return 1;
}

int main(int argc, char* argv[])
{
	int floor[FLOORSIZE][FLOORSIZE] = {0};
	enum Status status = CONTINUE;
	enum Orientation orientation = RIGHT;
	bool penDown = true;
	int cmd, steps;

	while(status==CONTINUE)
	{
		if(!scanf("%d, %d", &cmd, &steps))
		{
			cleanBuffer();
			cmd = 0;
		}
		switch(cmd)
		{
			case 1:
				penDown = false;
				break;
			case 2:
				penDown = true;
				break;
			case 3:
				if(orientation == LEFT)
					orientation = UP;
				else
					orientation++;
				break;
			case 4: 
				if(orientation == UP)
					orientation = LEFT;
				orientation--;
				break;
			case 5:
				if(move(floor, steps, orientation, penDown))
					printf("made move\n");
				else
					printf("invalid move\n");
				break;
			case 6:
				printFloor(floor);
				break;
			case 9:
				status = OVER;
				break;
			default:
				printf("invalid command\n");
				break;
		}
		//printf("%d\n", orientation);

	}
	
	
	return 0;
}
