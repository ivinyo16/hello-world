/**
 * @file valid_parenthesis.c
 * @author your name (you@domain.com)
 * @brief Make sure parenthesis are closed properly
 * 
 * Techniques used:
 *  - stacks
 * 
 * @version 0.1
 * @date 2022-07-30
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
    int *array;
}stack_t;

int isFull(stack_t *stack)
{
    return (stack->top >= stack->capacity-1);
}

int isEmpty(stack_t *stack)
{
    return (stack->top == -1);
}

int push(stack_t *stack, int val)
{
    if(isFull(stack))
    {
        return -1;
    }
    stack->array[++stack->top] = val;
    return 0;
}

int pop(stack_t *stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top--];
}

/**
 * @brief only delete if latest stack's val matches with input parameter
 * 
 */
int specialPop(stack_t *stack, int val)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    DEBUG_PRINT("%d  ----- %d\n", stack->array[stack->top] , val);
    if(stack->array[stack->top] == val)
    {
        return pop(stack);
    }
    else
    {
        return -1;
    }

}

stack_t * createStack(int capacity)
{
    stack_t *stack = (stack_t*)malloc(sizeof(stack_t));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(capacity*(sizeof(int)));
    return stack;
}

bool isValid(char * s)
{
    stack_t *stack = createStack(10000);

    while(*s != '\0')
    {
        switch (*s)
        {
        case '(':
            push(stack, 1);
            break;
        case '[':
            push(stack, 2);
            break;
        case '{':
            push(stack, 3);
            break;
        case ')':
            if(specialPop(stack, 1) < 0)
            {
                free(stack->array);
                free(stack);
                return false;
            }
            break;
        case ']':
            if(specialPop(stack, 2) < 0)
            {
                free(stack->array);
                free(stack);
                return false;
            }
            break;
        case '}':
            if(specialPop(stack, 3) < 0)
            {
                free(stack->array);
                free(stack);
                return false;
            }
            break;
        
        default:
            break;
        }
        s++;

    }
    if(isEmpty(stack))
    {
        free(stack->array);
        free(stack);
        return true;
    }
    free(stack->array);
    free(stack);
    return false;
}

int main(int argc, char* argv[])
{
    char *word= "({{{{}}}))";
    // char *word= "((()))";
    // char *word="aaa";

    printf("isValid: %s\n", isValid(word) ? "true" : "false");


    return 0;
}
