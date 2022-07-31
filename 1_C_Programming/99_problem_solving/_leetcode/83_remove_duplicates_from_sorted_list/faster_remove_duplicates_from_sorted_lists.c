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

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* cur = head;
    while (cur && cur->next) {
        if(cur->val == cur->next->val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return head;
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
