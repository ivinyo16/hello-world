/**
 * @file remove_linked_list_elements.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given the head of a linked list and an integer val, 
 * remove all the nodes of the linked list that has Node.val == val, and return the new head.
 * 
 * ex.
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 * 
 * @version 0.1
 * @date 2022-07-29
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


// Definition for singly-linked list.
struct ListNode 
{
    int val;
    struct ListNode *next;
};



void insertList(struct ListNode** head, int val)
{
    struct ListNode *current = *head;
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;


    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }



}

void printList(struct ListNode *head)
{
    struct ListNode *current = head;
    while(current != NULL)
    {
        printf("%d, ", current->val);
        current = current->next;
    }
    printf("\n");
}


struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* current = head;
    struct ListNode* temp;

    //1. Establish our new head
    while( head && head->val == val )
    {
        head = head->next;
        DEBUG_PRINT("new head\n");
    }
    current = head;

    while(current != NULL && current->next != NULL )
    {
        DEBUG_PRINT("check %d\n", current->next->val);

        temp = current->next;
        while( current->next->val == val)
        {
            DEBUG_PRINT("hit\n");
            temp = temp->next;
            if( temp == NULL )
            {
                current->next = NULL;
                break;
            }
            current->next = temp;
        }
        current = current->next;
        // DEBUG_PRINT("here %d\n", current->val);
    }



    return head;
}

int main(int argc, char* argv[])
{
    struct ListNode *list1 = NULL;
    struct ListNode *answer = NULL;

    insertList(&list1, 6);
    insertList(&list1, 1);
    insertList(&list1, 2);
    insertList(&list1, 6);
    insertList(&list1, 3);
    insertList(&list1, 4);
    insertList(&list1, 5);
    insertList(&list1, 6);


    // insertList(&list1, 6);
    // insertList(&list1, 6);
    // insertList(&list1, 6);
    // insertList(&list1, 6);
    // insertList(&list1, 5);

    printList(list1);

    answer = removeElements(list1, 6);

    printList(answer);

    // answer = 

    return 0;
}
