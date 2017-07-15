#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long (int hour, int minutes, int seconds)
{
	return hour*60*60 + minutes * 60 + seconds;
}

int main(int argc, char* argv[])
{
	int hour, min, seconds;
	scanf("%d %d %d", &hour, &min, &seconds);

	printf("%lu seconds\n", elapsedTime(hour,min,seconds));
		

	return 0;
}
