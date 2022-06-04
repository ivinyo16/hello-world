#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode 
{
    int val;
    struct ListNode *next;
};

/**
 * @brief create instance of a node at the beginning
 * 
 * @param node 
 * @param value 
 */
void prependNode(struct ListNode** head, int value)
{
    //1. Allocate memory of new node
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));

    //2. Assign value
    new_node->val = value;

    //3. next value will have current head's pointer
    new_node->next = *head;

    //4 Make head point to this new node
    (*head) = new_node;

}

void destroyLastNode(struct ListNode** head)
{
    if(*head == NULL)
    {
        return;
    }
    struct ListNode* temp = *head;
    struct ListNode* last_node;

    if((*head)->next == NULL)
    {
        *head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        last_node = temp->next;
        temp->next = NULL;
        free(last_node); 
    }
}

/**
 * @brief create an instance of a node at the end
 * 
 * @param node  previous node to be referenced, NULL if this is the header.
 * @param value  
 */
void appendNode(struct ListNode** head, int value)
{
    //1. allocate memory for new node
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));

    struct ListNode* last = *head;

    //2. set value of new node
    new_node->val = value;

    //3. set next to NULL for new node
    new_node->next = NULL;

    //4. check if reference head is empty
    if( *head == NULL )
    {
        *head = new_node;
        return;
    }

    //5. traverse until we reach end of linked list
    while( (last)->next != NULL )
    {
        last = (last)->next;
    }

    //6. set
    last->next = new_node;
    return;
}

/**
 * @brief print out all values of the Linked List 
 * 
 * @param node 
 */
void printLinkedList(struct ListNode* node)
{
    while( node != NULL)
    {
        printf("value: %d\n", node->val);
        node = node->next;
    }

    return;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    
    struct ListNode* last_1 = l1;
    struct ListNode* last_2 = l2;
    struct ListNode* sum_list = NULL;
    
    int list_1_count = 0;
    int list_2_count= 0;
    int sum_list_count = 0;
    int count= 0 ;
    int is_carry = 0;
    int addend_1 = 0, addend_2 = 0;
    int sum = 0;
    int modified_sum;

    //1. count number of nodes of each
    while(last_1 != NULL)
    {
        list_1_count++;
        last_1 = last_1->next;
    }
    while(last_2 != NULL)
    {
        list_2_count++;
        last_2 = last_2->next;
    }

    //2. determine size of memory to allocate sum List Node
    sum_list_count = (list_1_count >= list_2_count) ? list_1_count : list_2_count;
    sum_list_count++;
    // sum_list = (struct ListNode*) malloc((sum_list_count) * sizeof(struct ListNode));

    //3. get value for sum list
    last_1 = l1;
    last_2 = l2;
    for( count = 0 ; count < sum_list_count ; count++)
    {
        addend_1 = 0;
        addend_2 = 0;
        if(last_1 != NULL)
        {
            addend_1 = last_1->val;
            last_1 = last_1->next;
        }
        if(last_2 != NULL)
        {
            addend_2 = last_2->val;
            last_2 = last_2->next;
        }
        sum = addend_1 + addend_2;
        //check for previous carry
        if(is_carry)
        {
            sum++;
        }
        // we only want the ones digit
        modified_sum = sum % 10;

        // printf("modified_sum %d\n", modified_sum);
        //check for current carry
        is_carry = (sum/10);
        // printf("is_carry %d\n", is_carry);

        appendNode(&sum_list, modified_sum);
        
    }
    if(modified_sum == 0)
    {
        destroyLastNode(&sum_list);
    }
    printf("\n");
    printLinkedList(sum_list);
    return sum_list;
}

int main(int argc, char* argv[])
{
    struct ListNode* linked_list_1 = NULL;
    struct ListNode* linked_list_2 = NULL;
    struct ListNode* linked_list_sum = NULL;

    appendNode(&linked_list_1, 4);
    appendNode(&linked_list_1, 7);
    appendNode(&linked_list_1, 8);
    appendNode(&linked_list_1, 8);
    appendNode(&linked_list_1, 5);

    appendNode(&linked_list_2, 1);
    appendNode(&linked_list_2, 6);
    appendNode(&linked_list_2, 1);
    appendNode(&linked_list_2, 3);
    appendNode(&linked_list_2, 0);

    printLinkedList(linked_list_1);
    printf("\n");
    printLinkedList(linked_list_2);

    addTwoNumbers(linked_list_1, linked_list_2);


	return 0;
}
