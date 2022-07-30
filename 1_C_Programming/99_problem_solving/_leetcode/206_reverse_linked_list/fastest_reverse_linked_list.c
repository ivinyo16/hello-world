/**
 * @file reverse_linked_list.c
 * @author your name (you@domain.com)
 * @brief 
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * 
 * techniques used:
 *  - linked lists
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
        // printf("%p %d, ", current,current->val);
        current = current->next;
    }
    printf("\n");
}

struct ListNode* copyList(struct ListNode *src)
{
    struct ListNode *dest=NULL;
    struct ListNode *head=NULL;
    while(src != NULL)
    {
        if(dest == NULL)
        {
            dest = (struct ListNode*)malloc(sizeof(struct ListNode));
            dest->val = src->val;
            dest->next = NULL;
            head = dest;
        }
        else
        {
            while(dest->next != NULL)
            {
                dest = dest->next;
            }
            dest->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            dest->next->val = src->val;
            dest->next->next = NULL;
        }
        src = src->next;
    }
    return head;
}

struct ListNode* reverseList(struct ListNode* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    struct ListNode* headnew=(struct ListNode*)malloc(sizeof(struct ListNode));
    headnew->val=head->val;
    headnew->next=NULL;
    head=head->next;
    while(head!=NULL)
    {
        struct ListNode* tmp=headnew;
        headnew=head;            
        head=head->next;
        headnew->next=tmp;
    }
    return headnew;
}
int main(int argc, char* argv[])
{
    struct ListNode *list1 = NULL;
    struct ListNode *answer = NULL;
    struct ListNode *copy = NULL;

    insertList(&list1, 1);
    insertList(&list1, 2);
    insertList(&list1, 6);
    insertList(&list1, 3);
    insertList(&list1, 4);
    // insertList(&list1, 5);
    // insertList(&list1, 6);

    printList(list1);

    answer = reverseList(list1);

    printList(answer);

    return 0;
}
