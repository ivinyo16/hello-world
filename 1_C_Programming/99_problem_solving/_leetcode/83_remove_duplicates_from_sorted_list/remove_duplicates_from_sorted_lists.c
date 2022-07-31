/**
 * @file remove_duplicates_from_sorted_lists.c
 * @author your name (you@domain.com)
 * @brief Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
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

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    int cmp = -101; //constraint of value = -100 to 100
    struct ListNode* answer = head;
    if(head == NULL)
        return NULL;

    //1. always add first element
    cmp = head->val;


    while( head->next != NULL )//&& head->next != NULL )
    {
        DEBUG_PRINT("%d -- %d\n", head->next->val, cmp);
        if(head->next->val <= cmp)
        {
            DEBUG_PRINT("hit on %d\n", head->next->val);
            head->next = head->next->next;

        }
        else
        {
            cmp = head->next->val;
            head = head->next;
        }
    }

    //check last index

    return answer;
}

int main(int argc, char* argv[])
{
    struct ListNode* list1 = NULL;
    struct ListNode* answer = NULL;

    insertList(&list1, 1);
    insertList(&list1, 1);
    insertList(&list1, 1);
    // insertList(&list1, 3);
    // insertList(&list1, 3);

    printList(list1);
    answer = deleteDuplicates(list1);

    printList(answer);




    return 0;
}
