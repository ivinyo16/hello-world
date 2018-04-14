#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 12
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4

int direction = 0;


void printMaze(int maze[][12])
{
	int i,j;
	for(i = 0 ; i < 12 ; i++)
	{
		for( j = 0; j < 12 ; j++)
		{
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}


int *mazeTraverse(int maze[][SIZE], int  *ptr)
{
	//int currX = x;
	//int currY = y;
	int moved = 0;
	int new = 0;
	//int *ptr = &maze[x][y];
	//int *ptr = current;
	int *hand;
	// set direction if not set
	if (!direction)
		direction = RIGHT;
	
	//set right hand placement
	if(direction == RIGHT)
		hand = ptr + SIZE;
	else if(direction == UP)
		hand = ptr + 1;
	else if(direction == LEFT)
		hand = ptr - SIZE;
	else if(direction == DOWN)
		hand = ptr - 1;
	
	//check right hand status and update
	if(*hand == '.')
	{
		direction++;
		if(direction > 4)
			direction = RIGHT;
		if(direction == RIGHT)
			hand = ptr + SIZE;
		else if(direction == UP)
			hand = ptr + 1;
		else if(direction == LEFT)
			hand = ptr - SIZE;
		else if(direction == DOWN)
			hand = ptr - 1;
	}
	
	//will exit once a move has been established
	//while(currX == x && currY == y)
	while(!moved)
	{
		if(direction > 4)
			direction = RIGHT;
		//check forward of position
		if(direction == RIGHT)
		{
			if(*(ptr+1) != '#')
			{
				//*ptr = 'X';
				ptr = ptr + 1;
				*ptr = 'X';
				moved = 1;
				//x = x + 1;
				//new = x;
			}
			else
				direction = UP;
		}
		else if(direction == UP)
		{
			if(*(ptr-SIZE) != '#')
			{
				//*ptr = 'X';
				ptr = ptr - SIZE;
				*ptr = 'X';
				moved = 1;
				//y = y - 1;
				//new = y;
			}
			else
				direction = LEFT;
		}
		else if(direction == LEFT)
		{

			if(*(ptr-1) != '#')
			{
				//*ptr = 'X';
				ptr = ptr - 1;
				*ptr = 'X';
				moved  = 1;
				//x = x - 1;
				//new = x;
			}
			else
				direction = DOWN;
		}
		else if(direction == DOWN)
		{
			if(*(ptr+SIZE) != '#')
			{
				//*ptr = 'X';
				ptr = ptr + SIZE;
				*ptr = 'X';
				moved = 1;
				//y = y + 1;
				//new = y;
			}
			else
				direction = RIGHT;
		}
	}
	
#if 0
	if(*ptr == '#')
		return -1;
	//first hop (right)
	if(*(ptr+1) != '#')
	{
		ptr++;
		x++;
	}
	//bottom
	else if(*(ptr+12) != '#')
	{
		ptr+=12;
		y++;
	}
	else if(*(ptr-12) != '#')
	{
		ptr = ptr -12;
		y--;
	}
	else if(*(ptr-1) != '#')
	{
		ptr--;
		x--;
	}
#endif


	//printf("here %c\n", maze[x][y]);
	//printf("*ptr %c\n", *ptr);
	//printf("*hand %c\n", *hand);
	return ptr;
}

int main(int argc, char* argv[])
{
	int x = 6;
	int y  = 6;
	int keepGoing = 1;
	int i = 0;
	int j = 0;
	int maze[12][12] = {
		{'#','#','#','#','#','#','#','#','#','#','#','#'},
		{'#','.','.','.','#','.','.','.','.','.','.','#'},
		{'.','.','#','.','#','.','#','#','#','#','.','#'},
		{'#','#','#','.','#','.','.','.','.','#','.','#'},
		{'#','.','.','.','.','#','#','#','.','#','.','#'},
		{'#','#','#','#','.','#','.','#','.','#','.','#'},
		{'#','.','.','#','.','#','.','#','.','#','.','#'},
		{'#','#','.','#','.','#','.','#','.','#','.','#'},
		{'#','.','.','.','.','.','.','.','.','#','.','#'},
		{'#','#','#','#','#','#','.','#','#','#','.','#'},
		{'#','.','.','.','.','.','.','#','.','.','.','#'},
		{'#','#','#','#','#','#','#','#','#','#','#','#'},
	};
	int *current = &maze[x][y];
	
	while(keepGoing == 1)
	{
		current = mazeTraverse(maze, current);
		for( i = 0; i < SIZE; i++)
		{
			if(current == &maze[i][0] || current == &maze[i][SIZE-1])
				keepGoing = 0;
		}
		for( j = 0; j < SIZE; j++)
		{
			if(current == &maze[0][j] || current == &maze[SIZE-1][j])
				keepGoing = 0;
		}
		printMaze(maze);
		sleep(1);
		system("clear");

	}
	printf("done!\n");

	return 0;
}
