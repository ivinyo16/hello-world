/**
 * @file queue_using_stacks.c
 * @author your name (you@domain.com)
 * @brief 
 * Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
 * 
 * Implement the MyQueue class:
 * 
 * void push(int x) Pushes element x to the back of the queue.
 * int pop() Removes the element from the front of the queue and returns it.
 * int peek() Returns the element at the front of the queue.
 * boolean empty() Returns true if the queue is empty, false otherwise.
 * Notes:
 * 
 * You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 * @version 0.1
 * @date 2022-07-31
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

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif


typedef struct stack_t
{
    int top;
    int capacity;
    int array[100];
}stack_t;

int isStackFull(stack_t *stack)
{
    return (stack->top >= stack->capacity - 1);
}


int isStackEmpty(stack_t *stack)
{
    return ( stack->top <= -1 );
}

int stackPush(stack_t *stack, int val)
{
    if(isStackFull(stack))
    {
        return -1;
    }
    stack->array[++stack->top] = val;
    return 0;
}

int stackPop(stack_t *stack)
{
    if(isStackEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top--];
}


typedef struct {
    stack_t *bucket;
    stack_t *mug;
    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *queue = NULL;

    queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->bucket = (stack_t *)malloc(sizeof(stack_t));
    queue->mug = (stack_t *)malloc(sizeof(stack_t));

    queue->bucket->capacity = queue->mug->capacity = 100;
    queue->bucket->top = queue->mug->top = -1;


    return queue;
}

void myQueuePush(MyQueue* obj, int x) 
{
    stackPush(obj->bucket, x);
}

int myQueuePop(MyQueue* obj) 
{
    int removed_element;
    if(isStackEmpty(obj->bucket))
    {
        return -1;
    }

    //temp place others to mug
    while(obj->bucket->top > 0)
    {
        stackPush(obj->mug, obj->bucket->array[obj->bucket->top--]);
    }

    removed_element = obj->bucket->array[obj->bucket->top--];  //remove this

    //return back to bucket
    while(obj->mug->top >= 0)
    {
        stackPush(obj->bucket, obj->mug->array[obj->mug->top--]);
        
    }
    return removed_element;
}

int myQueuePeek(MyQueue* obj) 
{
    if(isStackEmpty(obj->bucket))
    {
        return -1;
    }
    return obj->bucket->array[0];
  
}

bool myQueueEmpty(MyQueue* obj) 
{
    return ((bool) isStackEmpty(obj->bucket));
}

void myQueueFree(MyQueue* obj) {
    free(obj->bucket);
    free(obj->mug);
    free(obj);
    obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

int main(int argc, char* argv[])
{
    MyQueue* obj = myQueueCreate();

    myQueuePush(obj, 2);
    myQueuePush(obj, 1);
    myQueuePush(obj, 3);


    printf("pop %d\n", myQueuePop(obj));
    printf("pop %d\n", myQueuePop(obj));
    printf("peek %d\n", myQueuePeek(obj));

    myQueueFree(obj);

    return 0;
}
