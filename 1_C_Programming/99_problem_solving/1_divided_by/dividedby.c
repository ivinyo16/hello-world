#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define RED "\e[0;31m"
#define NC "\e[0m"

typedef struct {
    unsigned quotient;
    unsigned remainder;
} divider_s;

// Implement (with all possible error checks)
void divide(divider_s* answer, unsigned number, unsigned divide_by);


/**
 * @brief Divide by routine
 *
 * Divide unsigned integer. Limited to only positive numbers up to INT_MAX. In most cases this is 2147483647
 *
 * @param answer - struct holding quotient, remainder. Should be allocated
 * @param number - dividend, limit to only INT_MAX
 * @param divide_by - divisor, limit to only INT_MAX
 *
 * @return none
 */
void divide(divider_s* answer, unsigned number, unsigned divide_by)
{
    if( answer == NULL )
    {
        fprintf(stderr, RED "memory not allocated\n");
        exit(EXIT_FAILURE);
    }

    if( divide_by == 0 )
    {
        fprintf(stderr, RED "invalid divisor\n");
        exit(EXIT_FAILURE);
    }

    if( number > INT_MAX )
    {
        fprintf(stderr, RED "dividend exceed allowed parameter limits\n");
        exit(EXIT_FAILURE);
    }

    if( divide_by > INT_MAX )
    {
        fprintf(stderr, RED "divisor exceed allowed parameter limits\n");
        exit(EXIT_FAILURE);
    }

    answer->quotient = number / divide_by;
    answer->remainder = number % divide_by;
}


int main(int argc, char* argv[])
{
    divider_s output;
    unsigned number = 226;
    unsigned divide_by = 2;


    divide( &output, number, divide_by );

    printf("quotient is %u\n", output.quotient);
    printf("quotient is %u\n", output.remainder);



    return 0;
}
