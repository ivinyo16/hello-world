#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int lengthOfLongestSubstring(char * s)
{
    int longest_count = 1;
    int current_count = 1;
    char * head = s;
    char * tail = s;
    char * between = s;
    int a;

        
    if(*s == '\0')
    {
        return 0;
    }
    
    while( *head != '\0' )
    {
        tail++;
        between = head;
        if( *tail == '\0')
        {
            head++;
            tail = head;
            break;
        }
        
        while(between != tail)
        {
            if(*between != *tail)
            {
                if(between == tail-1)
                {
                    current_count++;
                    if(current_count > longest_count)
                    {
                        longest_count = current_count;
                    }
                }
            }
            else
            {
                current_count = 1;
                head++;
                tail = head;
                break;
            }
            between++;
        }


    }
    
    return longest_count;
}

int main()
{

    char sample[] = "anviaj";
    // char sample[] = "cdd";
    int answer = 0;
    answer = lengthOfLongestSubstring(sample);


    printf("\nanswer: %d\n", answer);
    return 0;
}