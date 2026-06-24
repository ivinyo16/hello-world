/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-22
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

#include "node.h"
#include "queue_node.h"

// Create a new queue
Queue* createQueue() 
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(Queue* q, Node* node, int level) 
{
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->node = node;
    temp->level = level;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue
QueueNode* dequeue(Queue* q) 
{
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    return temp;
}

// Check if queue is empty
int isEmpty(Queue* q) 
{
    return q->front == NULL;
}

int getHeight(Node* root, int h) 
{
    if (root == NULL) return h - 1;
    int leftH = getHeight(root->left, h + 1);
    int rightH = getHeight(root->right, h + 1);
    return (leftH > rightH ? leftH : rightH);
}

void levelOrder(Node* root)
{
    Queue* queue = createQueue();
    enqueue(queue, root, 0);

    int lastLevel = 0;
    int height = getHeight(root, 0);

    while (!isEmpty(queue)) {
        QueueNode* top = dequeue(queue);
        Node* node = top->node;
        int lvl = top->level;
        free(top);

        if (lvl > lastLevel) {
            printf("\n");
            lastLevel = lvl;
        }

        // all levels are printed
        if (lvl > height) break;

        // printing null node
        if (node->data == -1) printf("N ");
        else printf("%d ", node->data);

        // null node has no children
        if (node->data == -1) continue;

        if (node->left == NULL) enqueue(queue, newNode(-1), lvl + 1);
        else enqueue(queue, node->left, lvl + 1);

        if (node->right == NULL) enqueue(queue, newNode(-1), lvl + 1);
        else enqueue(queue, node->right, lvl + 1);
    }
}
//Driver Code Ends