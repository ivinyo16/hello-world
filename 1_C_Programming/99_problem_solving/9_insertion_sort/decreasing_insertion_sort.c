#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE                 6

void sortInsertion(int * data, int buffer_size);

void sortInsertion(int * data, int buffer_size)
{
    int index = 0;
    int loop_index = 0;
    int temp = 0;

    for( index = buffer_size - 2 ; index >= 0 ; index-- )
    {
        temp = data[index];
        loop_index = index + 1;
        while ( loop_index < buffer_size && data[loop_index] > temp)
        {
            data[loop_index - 1] = data[loop_index];
            loop_index++;
            
            
        }

        data[loop_index - 1] = temp;
    }
}


int main(int argc, char* argv[])
{
    int cards[BUFFER_SIZE] = { 5, 2, 4, 6, 1,3 };

    sortInsertion(cards, BUFFER_SIZE);

    for ( int index = 0 ; index <  BUFFER_SIZE ; index++ )
    {
        printf("%d ", cards[index]);
    }
    puts("");
    return 0;
}
