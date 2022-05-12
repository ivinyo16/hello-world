#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE                 6

void sortSelection(int * data, int buffer_size);

void sortSelection(int * data, int buffer_size)
{
    int index = 0;
    int sub_index = 0;
    int smallest_number_index = 0;
    int temp = 0;

    for( index = 0 ; index < buffer_size ; index++ )
    {
        temp = data[index];
        smallest_number_index = index;

        for( sub_index = index + 1 ; sub_index < buffer_size ; sub_index++)
        {
            if( data[sub_index] < temp )
            {
                temp = data[sub_index];
                smallest_number_index = sub_index;
            }
        }

        data[smallest_number_index] = data[index];
        data[index] = temp;
        printf("data[smallest_number_index]: %d\n", data[smallest_number_index]);
        printf("data[index]: %d\n", data[index]);

    }

}


int main(int argc, char* argv[])
{
    int cards[BUFFER_SIZE] = { 5, 2, 4, 6, 1,3 };

    sortSelection(cards, BUFFER_SIZE);

    for ( int index = 0 ; index <  BUFFER_SIZE ; index++ )
    {
        printf("%d ", cards[index]);
    }
    puts("");
    return 0;
}
