#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char* argv[])
{

	//remove the need for enter key 
	system("/bin/stty raw");
	char c;
	c = getchar();
	printf("\n\rchar is %c\n\r", c);
	isdigit(c) ? printf("is digit\n\r") : printf("is not digit\n\r");
	isalpha(c) ? printf("is alpha\n\r") : printf("is not alpha\n\r");
	isalnum(c) ? printf("is a digit\n\r") : printf("is a letter\n\r");
	isxdigit(c) ? printf("is a hex\n\r") : printf("is not hex\n\r");
	isspace(c) ? printf("is space\n\r") : printf("is not space\n\r");
	//bring back to normal
	system("/bin/stty cooked");
	return 0;
}
