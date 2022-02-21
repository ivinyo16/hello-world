#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>

/**
* Write a function that will manage a list of timers and call an associated
* callback function when the timer expires. Also, when the timer expires, it
* shall be restarted.
*
* Given is an example timers configuration and the prototype for the main timer
* periodic task function.
*
* - Define the timer_s struct type based on 'timer_s timers_example' below
* - Implement the timer_periodic_task() function
* - Test your code in main()\
* - Create more timer configurations, if needed, for testing
*/

typedef struct 
{
	uint32_t time_remaining;
	uint32_t timer_reload_value;
	void (*callback)(void);
} timer_s;

void timer_0_callback(void) {
 // just for test
 puts("Timer 0 Callback");
}
void timer_1_callback(void) {
 // just for test
 puts("Timer 1 Callback");
}

/* Initial timer example configuration */
timer_s timers_example[] = {
   {
       .time_remaining = 0U,      // Timer starts at 0, so callback is triggered
       // When time_remaining goes to 0, this reload value is stored back to time_remaining
       .timer_reload_value = 5U, 
       .callback = timer_0_callback,  // Called when time_remaining reaches 0
   },
   {
       .time_remaining = 7U,          // Some initial value
       .timer_reload_value = 3U,      // reload value
       .callback = timer_1_callback,  // User callback
   },
};

// Assume this is called back upon each timer tick but for testing at main(), you can invoke this manually
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

int main() {
 // TODO test cases
 // Test your code here with calls to timer_periodic_task()

timer_s *timers_none;
timer_periodic_task(timers_none, sizeof(timers_none)/sizeof(timer_s));


 while(1)
 {
     sleep(1);
     timer_periodic_task(timers_example, sizeof(timers_example)/sizeof(timer_s));
 }
 return 0;
}



