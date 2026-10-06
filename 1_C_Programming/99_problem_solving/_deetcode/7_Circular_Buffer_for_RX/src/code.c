/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdatomic.h>
#include <stdint.h>

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

static uint8_t stack[16];
static int available_stack = 16;
static uint8_t *head = stack, *tail = stack;

int buf_push(uint8_t data);
int buf_pop(uint8_t* out);

int buf_push(uint8_t data)
{
    if(available_stack <= 0)
    {
        return -1;
    }
    /* put data */
    *head = data;

    /* increment pointer, but check if we've reached end to start at beginning */
    if(head++ == &stack[15])
    {
        head = &stack[0];
    }
    

    available_stack--;


    return 0;
}

int buf_pop(uint8_t* out)
{
    if(available_stack >= 16)
    {
        return -1;
    }

    /* put value onto output buffer */
    *out = *tail;

    /* increment pointer, but check if we've reached end to start at beginning */
    if(tail++ >= &stack[15])
    {
        tail = &stack[0];
    }
    available_stack++;
    return *out;
}



int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    uint8_t out = 0;

    DEBUG_PRINT("push: %d\n", buf_push(1));
    DEBUG_PRINT("push: %d\n", buf_push(2));
    DEBUG_PRINT("push: %d\n", buf_push(3));
    DEBUG_PRINT("push: %d\n", buf_push(4));
    DEBUG_PRINT("push: %d\n", buf_push(5));
    DEBUG_PRINT("push: %d\n", buf_push(6));
    DEBUG_PRINT("push: %d\n", buf_push(7));
    DEBUG_PRINT("push: %d\n", buf_push(8));
    DEBUG_PRINT("push: %d\n", buf_push(9));
    DEBUG_PRINT("push: %d\n", buf_push(10));
    DEBUG_PRINT("push: %d\n", buf_push(11));
    DEBUG_PRINT("push: %d\n", buf_push(12));
    DEBUG_PRINT("push: %d\n", buf_push(13));
    DEBUG_PRINT("push: %d\n", buf_push(14));
    DEBUG_PRINT("push: %d\n", buf_push(15));
    DEBUG_PRINT("push: %d\n", buf_push(16));
    DEBUG_PRINT("Next push should fail: \n");
    DEBUG_PRINT("push: %d\n", buf_push(17));
    DEBUG_PRINT("Lets pop: \n");
    DEBUG_PRINT("pop: %d ; ", buf_pop(&out));
    DEBUG_PRINT("value: %d \n",  out);
    DEBUG_PRINT("pop: %d ; ", buf_pop(&out));
    DEBUG_PRINT("value: %d \n",  out);
    DEBUG_PRINT("pop: %d ; ", buf_pop(&out));
    DEBUG_PRINT("value: %d \n",  out);
    DEBUG_PRINT("pop: %d ; ", buf_pop(&out));
    DEBUG_PRINT("value: %d \n",  out);
    DEBUG_PRINT("pop: %d ; ", buf_pop(&out));
    DEBUG_PRINT("value: %d \n",  out);
    DEBUG_PRINT("Next 5  push should succeed: \n");
    DEBUG_PRINT("push: %d\n", buf_push(18));
    DEBUG_PRINT("push: %d\n", buf_push(19));
    DEBUG_PRINT("push: %d\n", buf_push(20));
    DEBUG_PRINT("push: %d\n", buf_push(21));
    DEBUG_PRINT("push: %d\n", buf_push(22));
    DEBUG_PRINT("push: %d\n", buf_push(23));
    DEBUG_PRINT("Lets pop everything out, 17 failed earlier: \n");
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));
    DEBUG_PRINT("pop: %d\n", buf_pop(&out));



    return 0;
}
