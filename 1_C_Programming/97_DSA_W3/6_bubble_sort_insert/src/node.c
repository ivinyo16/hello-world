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

Node* newNode( int val )
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}


/**
 * 
 */
Node* insert( Node* root, int key)
{
    Node* temp;
    Node* curr = root;

    if(root == NULL)
    {
        return newNode(key);
    }

    temp = newNode(key);

    // Find the node who is going to
    // have the new node as its child
    while ( curr != NULL )
    {
        if ( key < curr->data && curr->left != NULL )
        {
            curr = curr->left;
        }
        else if( key > curr->data && curr->right != NULL)
        {
            curr = curr->right;
        }
        else
        {
            break;
        }
    }



    if( key < curr->data )
    {
        curr->left = temp;
    }
    else if ( key > curr->data )
    {
        curr->right = temp;
    }

    return root;
}