/* Fig. 8.14: fig08_14.c
Using getchar and puts */
#include <stdio.h>
int main( void )
{
char c; /* variable to hold character input by user */
char sentence[ 80 ]; /* create char array */
int i = 0; /* initialize counter i */
/* prompt user to enter line of text */
puts( "Enter a line of text:" );
/* use getchar to read each character */
while ( ( c = getchar() ) != '\n') {
sentence[ i++ ] = c;
} /* end while */
printf("here: %c\n", sentence[0]);
sentence[ i ] = '\0'; /* terminate string */
/* use puts to display sentence */
puts( "\nThe line entered was:" );
puts( sentence );
return 0; /* indicates successful termination */
} /* end main */