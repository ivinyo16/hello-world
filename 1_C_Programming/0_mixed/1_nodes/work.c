#include <stdlib.h>
#include <stdio.h>	
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
//printf("here/n");
Node* insert(Node *head,int data)
{
    //Complete this function
	Node *node = NULL;
	Node *temp;
	if(head == NULL)
	{
		node = malloc(sizeof *node);
		node->data = data;
		node->next = NULL;
		return node;
	}
	else
	{
		if(head->next == NULL)
			head->next = node;
		else
			node = head->next;
		while(node)
		{

			//node->next = node;
			if(node->next == NULL)
			{
				printf("here6\n");
				temp = node;
			}
			node = node->next;
		}
		node = malloc(sizeof *node);
		node->data = data;
		node->next = NULL;
		temp->next = node;
		if(head->next == NULL)
		{
			head->next = node;
		}
	}
    return head;
}

void display(Node *head)
{
	Node *start=head;
	while(start)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
int main()
{
	int T,data;
    scanf("%d",&T);
    Node *head=NULL;	
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    }
  display(head);
		
}