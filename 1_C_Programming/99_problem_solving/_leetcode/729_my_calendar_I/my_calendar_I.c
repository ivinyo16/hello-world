/**
 * @file my_calendar_I.c
 * @author your name (you@domain.com)
 * @brief 
 *  You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.
 * 
 * A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).
 * 
 * The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.
 * 
 * Implement the MyCalendar class:
 * 
 * MyCalendar() Initializes the calendar object.
 * boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 * 
 * 
 * 
 * @version 0.1
 * @date 2022-08-03
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

typedef struct node_t
{
    int left_key;
    int weak_right_key;
    struct node_t *left;
    struct node_t *right;
}node_t;

typedef struct MyCalendar
{
    int max_nodes;
    int tail;
    node_t **node;
}MyCalendar;



MyCalendar* myCalendarCreate() 
{
    int capacity = 1000;
    MyCalendar *head = (MyCalendar *) malloc( sizeof(MyCalendar));
    head->max_nodes = capacity;
    head->tail = -1;
    head->node = (node_t**)malloc(capacity*sizeof(node_t *));
    for(int i = 0 ; i < capacity ; i++ )
    {
        head->node[i] = NULL;
    }
    return head;
}


bool myCalendarBook(MyCalendar* obj, int start, int end) 
{
    node_t **node_head = obj->node;
    node_t *cur_node = *node_head;
    printf("obj->node %p\n", obj->node);
    printf("cur_node %p\n", cur_node);

    if(cur_node == NULL)
    {
        DEBUG_PRINT("null\n");
        cur_node = (node_t *)malloc(sizeof(node_t));
        cur_node->left_key = start;
        cur_node->weak_right_key = end;
        cur_node->left = cur_node->right = NULL;
        obj->node = &cur_node;
        obj->tail++;
        return true;
    }

    while(cur_node != NULL)
    {
        if( cur_node->left == NULL && (start < cur_node->left_key && end < cur_node->left_key) )
        {
            cur_node->left = (node_t *)malloc(sizeof(node_t));
            cur_node->left->left_key = start;
            cur_node->left->weak_right_key = end;
            cur_node->left->left = cur_node->left->right = NULL;
            return true;
        }
        else if( cur_node->right == NULL && (start >= cur_node->weak_right_key && end > cur_node->weak_right_key) )
        {
            cur_node->right = (node_t *)malloc(sizeof(node_t));
            cur_node->right->left_key = start;
            cur_node->right->weak_right_key = end;
            cur_node->right->left = cur_node->right->right = NULL;
            return true;
        }

        if(cur_node->left && start < cur_node->left_key && end < cur_node->left_key)
        {
            cur_node = cur_node->left;
        }
        else if(cur_node->right && start >= cur_node->weak_right_key && end > cur_node->weak_right_key)
        {
            cur_node = cur_node->right;
        }
        else
        {
            return false;
        }
    }

    return false;
}

void freeTreeWalk(node_t *head)
{
    if(head != NULL)
    {
        freeTreeWalk(head->left);
        freeTreeWalk(head->right);
        free(head);
    }
    
}

void myCalendarFree(MyCalendar* obj) 
{
    if(obj)
    {
        node_t **nodes = obj->node;
        node_t *node = *nodes;
        freeTreeWalk(node);
        free(obj);
    }
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
 */

int main(int argc, char* argv[])
{
    MyCalendar* obj = myCalendarCreate();
    int x = 10;
    int y = 20;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 15;
    y = 25;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 20;
    y = 30;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    // x = 0;
    // y = 1;
    // printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );

    myCalendarFree(obj);

    return 0;
}
