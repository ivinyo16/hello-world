/**
 * @file linked_list_cycle.c
 * @author your name (you@domain.com)
 * @brief 
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * 
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
 * 
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 *  BASICALLY DETECT IF LINKED LIST IS CYCLIC
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
 * @version 0.1
 * @date 2022-07-28
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

struct ListNode 
{
    int val;
    struct ListNode *next;
};


bool hasCycle(struct ListNode *head) 
{
    struct ListNode *walker;
    struct ListNode *runner;
    
    if(head==NULL || head->next==NULL)
    {
        return false;
    }
    walker = head;
    runner = head->next;

    while(walker != NULL || runner != NULL)
    {
        DEBUG_PRINT("walker val: %d\n", walker->val);
        DEBUG_PRINT("runner val: %d\n", runner->val);
        if(walker == runner)
        {
            return true;
        }

        walker = walker->next;
        if(runner->next == NULL || runner->next->next == NULL)
        {
            return false;
        }
        runner = runner->next->next;
    }
    return false;
    
}

int main(int argc, char* argv[])
{




    return 0;
}
