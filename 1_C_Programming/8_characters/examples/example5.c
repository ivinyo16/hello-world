#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char a[30] = "12345.asdcas.^&*^*&^";
	char c[10] = "I was here";
	char *d=NULL;
	char e[30] = "pringles is life";
	char  * const g = "arraythatiwasthefirst";
	char *b= NULL;
	size_t n = 5;
	
	b = strtok(a,".");
	printf("token: %s\n", a);
	//while(b != NULL)
	for(b == NULL; b != NULL; b = strtok(NULL,"."))
	{
		//b = strtok(NULL,".");
		printf("strtok: %s\n", b);
	}
	
	stpcpy(c,a);
	printf("%s\n", a);

	
	d = malloc(sizeof(char *) *10);	
	memcpy(d,a, 5);
	printf("memcpy: %s\n", d);
	
	//safe to "copy" from the same string
	memmove(e,a,5);
	printf("memmove: %s %s\n", e,a);
	
	printf("test: %s\n", g);
	memset(g,0,sizeof(g));
	strcpy(g,c);
	printf("test2: %s\n", g);

	
	

	return 0;
}
