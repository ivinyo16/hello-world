/**
 * @file merge_two_sorted_lists.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 * 
 * Techniques used:
 * - Linked List
 * 
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


/**
 * @brief merge two LISTS, assumes sub lists are already sorted
 * 
 * @param list1 sorted list
 * @param list2 sorted list
 * @return struct ListNode* 
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* merged = NULL;
    struct ListNode* current = NULL;
    struct ListNode* left = list1;
    struct ListNode* right = list2;

    if( left == NULL && right == NULL )
    {
        return merged;
    }

    merged = (struct ListNode*)malloc(sizeof(struct ListNode));
    current = merged;

    if( left != NULL && right != NULL)
    {
        if( left->val <= right->val )
        {
            memcpy(current, left, sizeof(struct ListNode));
            left = left->next;
            current->next = NULL;
        }
        else
        {
            memcpy(current, right, sizeof(struct ListNode));
            right = right->next;
            current->next = NULL;
        }
    }
    else if(left == NULL)
    {
        memcpy(current, right, sizeof(struct ListNode));
        right = right->next;
        current->next = NULL;
    }
    else if(right == NULL)
    {
        memcpy(current, left, sizeof(struct ListNode));
        left = left->next;
        current->next = NULL;
    }

    while( left != NULL  && right != NULL)
    {
        if( left->val <= right->val )
        {
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            memcpy(current->next, left, sizeof(struct ListNode));
            left = left->next;
            current = current->next;
        }
        else
        {
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            memcpy(current->next, right, sizeof(struct ListNode));
            right = right->next;
            current = current->next;
        }
    }

    while( left != NULL )
    {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        memcpy(current->next, left, sizeof(struct ListNode));
        left = left->next;
        current = current->next;
    }

    while( right != NULL )
    {
        DEBUG_PRINT("ONE\n");
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        memcpy(current->next, right, sizeof(struct ListNode));
        right = right->next;
        current = current->next;
    }

    return merged;
}

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


int main(int argc, char* argv[])
{
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    struct ListNode *answer = NULL;

    insertList(&list1, 1);
    insertList(&list1, 2);
    insertList(&list1, 4);
    insertList(&list2, 0);
    insertList(&list2, 1);
    insertList(&list2, 3);
    insertList(&list2, 4);


    printList(list1);
    printList(list2);

    answer = mergeTwoLists(list1, list2);

    printList(answer);

    return 0;
}
