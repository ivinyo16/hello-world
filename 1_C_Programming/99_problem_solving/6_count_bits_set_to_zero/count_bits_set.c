#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    unsigned int number;
    int count = 0;
    uint32_t *mem_a, *mem_b;
    uint32_t *index = mem_a;
    printf("enter mem_a region: ");
    scanf("%p", &mem_a);
    printf("enter mem_b region: ");
    scanf("%p", &mem_b);

    printf("Memory address of num = %p\n", mem_a);

 
    while(1)
    {
        while (*index != 0)
        {
            if ((*index & 1) == 0)
            {
                count++;
            }
            *index = *index >> 1;
        }

        if(index == mem_b)
        {
            break;
        }
        index++;
    }
    printf("number of zero's are :\n%d\n", count);
    return 0;


    return 0;
}
