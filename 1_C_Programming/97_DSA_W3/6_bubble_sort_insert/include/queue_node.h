#ifndef MY_QUEUE_NODE_H
#define MY_QUEUE_NODE_H

#include "node.h"

// Queue node for level order traversal
typedef struct QueueNode {
    Node* node;
    int level;
    struct QueueNode* next;
} QueueNode;

// Queue structure
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
}Queue;

/* Function Prototypes*/
void enqueue(Queue* q, Node* node, int level);
QueueNode* dequeue(Queue* q);
int isEmpty(Queue* q);
int getHeight(Node* root, int h);
void levelOrder(Node* root);

#endif // MY_QUEUE_NODE_H