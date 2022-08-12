/**
 * @file lowest_common_ancestry.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and 
 * q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Ex.
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 *
 * 
 * 
 * @version 0.1
 * @date 2022-08-12
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

struct TreeNode *initialize(struct TreeNode *head, int capacity)
{
    return head;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    int smaller_number, bigger_number;
    struct TreeNode* ancestor = root;

    if( p->val < q->val )
    {
        smaller_number = p->val;
        bigger_number = q->val;
    }
    else
    {
        smaller_number = q->val;
        bigger_number = p->val;
    }

    while(ancestor != NULL)
    {
        if(smaller_number == ancestor->val || bigger_number == ancestor->val)
        {
            return ancestor;
        }
        if( smaller_number < ancestor->val && bigger_number > ancestor->val)
        {
            return ancestor;
        }
        if( smaller_number,bigger_number > ancestor->val)
        {
            ancestor = ancestor->right;
        }
        if( smaller_number,bigger_number < ancestor->val)
        {
            ancestor = ancestor->left;
        }
    }

    return NULL;
}

int main(int argc, char* argv[])
{
    struct TreeNode *my_tree = NULL;
    struct TreeNode *search_tree = NULL;
    my_tree = insertNode(my_tree, 6);
    insertNode(my_tree, 2);
    insertNode(my_tree, 8);
    insertNode(my_tree, 0);
    insertNode(my_tree, 4);
    insertNode(my_tree, 7);
    insertNode(my_tree, 9);
    insertNode(my_tree, 3);
    insertNode(my_tree, 5);

    inorderTreeWalk(my_tree);


    search_tree = findNode(my_tree, 6);
    if(search_tree)
    {
        printf("found\n");
    }

    struct TreeNode *p_tree = findNode(my_tree, 3);
    struct TreeNode *q_tree = findNode(my_tree, 5);
    struct TreeNode *answer_tree = NULL;
    answer_tree = lowestCommonAncestor(my_tree, p_tree, q_tree);
    if(answer_tree)
    {
        printf("lowest common ancester tree has value: %d\n", answer_tree->val);
    }

    freeTreeWalk(my_tree);


    return 0;
}
