#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

/**
 * @brief Create a Node object via preorder (root -> left -> right)
 * 
 * @param root_node 
 * @param val 
 */
void createNode(struct TreeNode **root_node, int value)
{
    //1. Allocate space for new node
    struct TreeNode *new_node = ( struct TreeNode *)malloc(sizeof(struct TreeNode));

    struct TreeNode *current_node = NULL;

    //2. Assign value to node's value
    new_node->val = value;

    //3. Assign new_node as root node if no root exists
    if( *root_node == NULL )
    {
        *root_node = new_node;
        (*root_node)->left = NULL;
        (*root_node)->right = NULL;
        return;
    }

    current_node = *root_node;
    while(current_node != NULL)
    {
        if( current_node->left == NULL )
        {
            current_node->left = new_node;
            return;
        }

        if( current_node->right == NULL )
        {
            current_node->right = new_node;
            return;
        }
        
    }

}

int main(int argc, char* argv[])
{





    return 0;
}
