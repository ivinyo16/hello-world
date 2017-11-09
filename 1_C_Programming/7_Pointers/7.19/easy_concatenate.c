/* ex07_19.c */
/* What does this program do? */
#include <stdio.h>
void mystery1( char *s1, const char *s2 ); /* prototype */
int main( void )
{
char string1[ 80 ]; /* create char array */
char string2[ 80 ]; /* create char array */
printf( "Enter two strings: " );
scanf( "%s%s" , string1, string2 );
mystery1( string1, string2 );
printf("%s\n", string1 );
return 0; /* indicates successful termination */
} /* end main */
/* What does this function do? */
void mystery1( char *s1,  const char *s2 )
{
while ( *s1 != '\0' ) {
s1++;
} /* end while */
for ( ; *s1 = *s2 ; s1++, s2++ ) {
printf("bi: %c\n", *s1); /* empty statement */
} /* end for */
printf("the value is: -%c-\n", *s1);
} /* end function mystery1 */