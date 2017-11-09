/* Fig. 7.16: fig07_16.c
Applying sizeof to an array name returns
the number of bytes in the array. */
#include <stdio.h>
size_t getSize( double *ptr ); /* prototype */
int main( void )
{
double array[ 20 ] = {0, 1}; /* create array */
printf( "The number of bytes in the array is %zu"
"\nThe number of bytes returned by getSize is %zu\n",
sizeof( array ), getSize( array ) );
return 0; /* indicates successful termination */
} /* end main */
/* return size of ptr */
size_t getSize( double *ptr )
{
printf("%f -  %p\n", *ptr, ptr);
ptr++;
printf("%f -  %p\n", *ptr, ptr);
return sizeof( ptr );
} /* end function getSize */
