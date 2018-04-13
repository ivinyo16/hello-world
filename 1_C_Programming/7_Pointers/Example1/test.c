#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void convert(char *bes)
{
	while( *bes !='\0' )
	{
		if(islower(*bes))
			*bes = toupper(*bes);
		bes++;
	}
}

int main(int argc, char* argv[])
{

	char sex[] = "what is this";
	printf("%s\n",sex);
	convert(sex);
	printf("%s\n", sex);

	return 0;
}
