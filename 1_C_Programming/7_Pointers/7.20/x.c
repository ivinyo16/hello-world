/* ex07_20.c */
/* what does this program do? */
#include <stdio.h>
int mystery2( const char *s ); /* prototype */
int main( void )
{
char string[ 80 ]; /* create char array */
	printf( "Enter a string: ");
scanf( "%s", string );
printf( "%d\n", mystery2( string ) );
return 0; /* indicates successful termination */
} /* end main */
/* What does this function do? */
int mystery2( const char *s )
{
int x; /* counter */
/* loop through string */
for ( x = 0; *s != '\0'; s++ ) {
x++;
} /* end for */
return x;
} /* end function mystery2 */