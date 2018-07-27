#include <stdio.h>
void reverse( const char * const sPtr ); /* prototype */
int main( void )
{
char sentence[ 80 ]; /* create char array */
printf( "Enter a line of text:\n" );
/* use fgets to read line of text */
fgets( sentence, 80, stdin );
printf( "\nThe line printed backward is:\n" );
reverse( sentence );
printf( "\n");
return 0; /* indicates successful termination */
} /* end main */
/* recursively outputs characters in string in reverse order */
void reverse( const char * const sPtr )
{
/* if end of the string */
if ( sPtr[ 0 ] == '\0' ) { /* base case */
return;
} /* end if */
else { /* if not end of the string */
reverse( &sPtr[ 1 ] ); /* recursion step */
putchar( sPtr[ 0 ] ); /* use putchar to display character */
} /* end else */
} /* end function reverse */