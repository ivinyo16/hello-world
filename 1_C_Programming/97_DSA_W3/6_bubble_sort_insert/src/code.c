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

/* User include */
#include "node.h"
#include "queue_node.h"

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif







int main(int argc, char* argv[])
{
    Node *root = NULL;

    root = insert(root, 22);
    root = insert(root, 12);
    root = insert(root, 30);
    root = insert(root, 8);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);

    // print the level order 
    // traversal of the BST
    levelOrder(root);


    return 0;
}
