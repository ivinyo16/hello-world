#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char * makeUpper(const char line[], int size)
{
	char *upper = malloc(sizeof(char*)*size);
	for( int ctr = 0 ; ctr < size ; ctr++)
	{
		upper[ctr] = toupper(line[ctr]);
	}
	return upper;
}

char * makeLower(const char line[], int size)
{
	char *lower = malloc(sizeof(char*)*size);
	for( int ctr = 0 ; ctr < size ; ctr++)
	{
		lower[ctr] = tolower(line[ctr]);
	}
	return lower;
}

int main(int argc, char* argv[])
{
	system("/bin/stty raw");
	char line[80]={0};
	int c;
	int i = 0;
#if 1
	while( (c = getchar()) != '\n')
	{
		line[i++] = c;
	}
#else
	fgets(line, 80, stdin);
#endif
	//puts(line);
	printf("%s\r\n", line);
	
	
	printf("uppercase: %s\r\n", (makeUpper(line, 80)));
	printf("uppercase: %s\r\n", (makeLower(line, 80)));
	
	
	system("/bin/stty cooked");
	return 0;
}
