/**
 * @file validate_binary_search_tree.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * A valid BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with vals less than the node's val.
 * The right subtree of a node contains only nodes with vals greater than the node's val.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * techniques used:
 * - binary trees
 * - recursion
 * 
 * @version 0.1
 * @date 2022-08-11
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



struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * @brief traverse whole tree from left to right
 * 
 * @param head 
 */
void inorderTreeWalk(struct TreeNode *head)
{
    if(head != NULL)
    {
        inorderTreeWalk(head->left);
        printf("%d, ", head->val);
        inorderTreeWalk(head->right);
    }
}

struct TreeNode *getLeftMostData(struct TreeNode *head)
{
    struct TreeNode * prev_head = NULL;
    if(head != NULL)
    {
        prev_head = getLeftMostData(head->left);
        if(prev_head)
        {
            printf("%d ? %d, \n", prev_head->val, head->val);
        }
        return head;
        // getLeftMostData(head->right);
    }
    return head;
}

bool isValidBSTAux(struct TreeNode* root, int  long low, int  long high)
{
    struct TreeNode* head = root;

    if(!head)
    {
        return true;
    }

    if(head->val >= high)
    {
        return false;
    }

    if(head->val <= low)
    {
        return false;
    }

    if(head->left && (head->left->val >=  head->val)  )
    {
        return false;
    }

    if(head->right && (head->right->val <= head->val)  )
    {
        return false;
    }


    bool b_left = isValidBSTAux(head->left, low, head->val);
    bool b_right = isValidBSTAux(head->right, head->val, high);

    if(!b_left || !b_right)
    {
        return false;
    }

    return true;
}

bool isValidBST(struct TreeNode* root)
{
    int long low = LONG_MIN;
    int long high = LONG_MAX;
    return isValidBSTAux(root, low, high);
}

void freeTreeWalk(struct TreeNode *head)
{
    if(head != NULL)
    {
        freeTreeWalk(head->left);
        freeTreeWalk(head->right);
        free(head);
    }
}

/**
 * @brief returns pointer to node containing given val, else return NULL
 * 
 * @param tree root tree
 * @param val 
 * @return struct TreeNode* 
 */
struct TreeNode * findNode(struct TreeNode *tree, int val)
{
    if(tree == NULL)
    {
        return NULL;
    }

    struct TreeNode *current = tree;

    while(current != NULL)
    {
        if(current->val == val)
        {
            return current;
        }
        else if(current->val < val)
        {
            current = current->right;
        }
        else if(current->val > val)
        {
            current = current->left;
        }
    }

    return NULL;
    
}

struct TreeNode * insertNode(struct TreeNode *tree, int val)
{
    if(tree == NULL)
    {
        tree = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        tree->val = val;
        tree->left = tree->right = NULL;
    }

    if(val < tree->val)
    {
        tree->left = insertNode(tree->left, val);
    }
    else if (val > tree->val)
    {
        tree->right = insertNode(tree->right, val);
    }

    return tree;

}

struct TreeNode * wronginsertNode(struct TreeNode *tree, int val)
{
    if(tree == NULL)
    {
        tree = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        tree->val = val;
        tree->left = tree->right = NULL;
    }

    if(val < tree->val)
    {
        tree->right = wronginsertNode(tree->right, val);
    }
    else if (val > tree->val)
    {
        tree->left = wronginsertNode(tree->left, val);
    }

    return tree;

}

struct TreeNode *initialize(struct TreeNode *head, int capacity)
{
    return head;
}

int main(int argc, char* argv[])
{
    struct TreeNode *my_tree = NULL;
    struct TreeNode *search_tree = NULL;
    bool answer = false;
    DEBUG_PRINT("%d\n", INT_MAX);
    my_tree = insertNode(my_tree, 2147483647);
    insertNode(my_tree, 2);
    insertNode(my_tree, 8);
    insertNode(my_tree, 5);
    insertNode(my_tree, 6);
    insertNode(my_tree, 7);
    insertNode(my_tree, 1);
    insertNode(my_tree, 9);
    insertNode(my_tree, 11);
    insertNode(my_tree, 10);
    insertNode(my_tree, 12);
    insertNode(my_tree, 13);
    insertNode(my_tree, 14);
    insertNode(my_tree, 15);


    inorderTreeWalk(my_tree);
    answer = isValidBST(my_tree);
    printf("\nis valid bst: %s\n", answer ? "true" : "false" );


    search_tree = findNode(my_tree, 6);
    if(search_tree)
    {
        printf("found\n");
    }

    freeTreeWalk(my_tree);


    return 0;
}
