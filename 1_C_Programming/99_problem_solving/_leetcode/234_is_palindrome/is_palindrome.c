/**
 * @file code
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given the head of a singly linked list, return true if it is a palindrome.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,2,1]
 * Output: true
 * Example 2:
 * 
 * 
 * Input: head = [1,2]
 * Output: false
 *  
 * 
 * Constraints:
 * 
 * The number of nodes in the list is in the range [1, 105].
 * 0 <= Node.val <= 9
 *  
 * 
Follow up: Could you do it in O(n) time and O(1) space?
 * 
 * @version 0.1
 * @date 2022-08-22
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
        current = current->next;
    }
    printf("\n");
}

bool isPalindrome(struct ListNode* head)
{
    
    int count = 1;

    //0. if by itself, it is a palindrome
    if(head->next == NULL)
    {
        return true;
    }

    //1. traverse and count number of nodes
    struct ListNode * current = head;
    while(current->next != NULL)
    {
        count++;
        current = current->next;
    }
    DEBUG_PRINT("count %d\n", count);

    //2. check first outer edges, since we already have tail, might as well
    if(head->val != current->val)
    {
        return false;
    }
    count=count - 2;
    if(count <= 1)
    {
        return true;
    }
    DEBUG_PRINT("count %d array size %d \n", count, count/2);

    struct ListNode *map[count/2];
    int half;
    current = head->next;

    if(count%2 == 0)
    {
        half = count/2;
    }
    else
    {
        half = (count/2) +1;
    }

    int idx = 0;
    for(int i = 0 ; i < count ; i++)
    {
        DEBUG_PRINT("%d %d\n", i, current->val);
        // DEBUG_PRINT("val %d \n", current->val);
        if(i >= half)
        {
            map[idx++] = current;
            // DEBUG_PRINT("map %d \n", map[0]->val);
        }
        current = current->next;
    }

    //3. time to check
    current = head->next;
    for( int i = idx-1 ; i >= 0 ; i-- )
    {
        // DEBUG_PRINT("map[%d] %d \n", i, map[i]->val);
        if(current->val != map[i]->val)
        {
            return false;
        }
        current = current->next;
    }

    return true;
}


int main(int argc, char* argv[])
{
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    bool answer = false;

    insertList(&list1, 1);
    insertList(&list1, 0);
    insertList(&list1, 1);
    // insertList(&list1, 2);
    // insertList(&list1, 3);
    // insertList(&list1, 2);
    // insertList(&list1, 1);
    // insertList(&list1, 5);


    printList(list1);

    answer = isPalindrome(list1);
    printf("answer: %s\n", answer ? "true" : "false" );





    return 0;
}
