#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>


typedef struct 
{
	uint32_t time_remaining;
	uint32_t timer_reload_value;
	void (*callback)(void);
} timer_s;

void timer_0_callback(void) 
{
    puts("Timer 0 Callback");
}
void timer_1_callback(void) 
{
    puts("Timer 1 Callback");
}

/* Initial timer example configuration */
timer_s timers_example[] = 
{
   {
       .time_remaining = 0U,
       .timer_reload_value = 5U,
       .callback = timer_0_callback,
   },
   {
       .time_remaining = 7U,
       .timer_reload_value = 3U,
       .callback = timer_1_callback,
   },
};

void timer_periodic_task(timer_s* timers, size_t timers_array_size) 
{
    int index;

    if( timers == NULL )
    {
        fprintf(stderr, "memory not allocated\n");
        return;
    }

    for( index = 0 ; index < timers_array_size; index++)
    {
        if( ((&timers[index])->time_remaining) > INT_MAX )
        {
            (&timers[index])->time_remaining = (&timers[index])->timer_reload_value;
            printf("handle invalid timer value\n");
            continue;
        }

        if( (&timers[index])->time_remaining == 0 || --(&timers[index])->time_remaining == 0)
        {
            (&timers[index])->callback();
            (&timers[index])->time_remaining = (&timers[index])->timer_reload_value;
        }
    }
}

int main() 
{
    timer_s *timers_none;
    timer_periodic_task(timers_none, sizeof(timers_none)/sizeof(timer_s));


    while(1)
    {
        sleep(1);
        timer_periodic_task(timers_example, sizeof(timers_example)/sizeof(timer_s));
    }
    return 0;
}



