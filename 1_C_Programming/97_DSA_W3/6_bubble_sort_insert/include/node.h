#ifndef MY_NODE_H
#define MY_NODE_H

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

/**
 *  Function Prototyopes
 */
Node* insert( Node* root, int key);
Node* newNode( int val );


#endif // MY_HEADER_H