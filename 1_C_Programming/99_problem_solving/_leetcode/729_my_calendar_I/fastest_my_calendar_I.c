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

// #define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

struct node{
    int start;
    int end;
  struct node *next;  
};

typedef struct {
    struct node *head;
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar *p;
    p = malloc(sizeof(MyCalendar));
    p->head = NULL;
    return p;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
  struct node *p = obj->head;
    bool res = true;
    bool made = false;
    struct node *prev = obj->head;
    while(p){
        if(p->start < end && p->end > start){
            res = false;
            break;
        }
        if(p->start >= end){
            struct node *t;
            t = malloc(sizeof(struct node));
            t->start = start;
            t->end = end;
            made = true;
            if(prev == p){ //the first
                t->next = p;
                obj->head = t;
            } else{ // seconde
                prev->next = t;
                t->next = p;
            }
            break;
        }
        prev = p;
        p = p->next;
    }
    if(res == true && made == false){ // the last
        struct node *t;
        t = malloc(sizeof(struct node));
        t->start = start;
        t->end = end;
        t->next = NULL;
        if(prev)
            prev->next = t;
        else
            obj->head = t;
    }
    return res;
}

void myCalendarFree(MyCalendar* obj) {
    struct node *p;
    struct node *t;
    p = obj->head;

    while(p){
        t = p->next;
        free(p);
        p = t;
    }
    return;
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
    int x = 47;
    int y = 50;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 33;
    y = 41;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 39;
    y = 45;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 33;
    y = 42;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );

    x = 25;
    y = 32;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 26;
    y = 35;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 19;
    y = 25;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 3;
    y = 8;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 8;
    y = 13;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );
    x = 18;
    y = 27;
    printf("adding %d to %d: %s\n", x, y, myCalendarBook(obj, x, y) ? "true" : "false" );


    myCalendarFree(obj);

    return 0;
}