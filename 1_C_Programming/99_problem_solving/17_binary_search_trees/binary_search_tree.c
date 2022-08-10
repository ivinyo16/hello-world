/**
 * @file binary_search_tree.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.2
 * @date 2022-08-03
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



typedef struct tree_t
{
    int key;
    struct tree_t *left;
    struct tree_t *right;
}tree_t;

/**
 * @brief traverse whole tree from left to right
 * 
 * @param head 
 */
void inorderTreeWalk(tree_t *head)
{
    if(head != NULL)
    {
        inorderTreeWalk(head->left);
        printf("%d, ", head->key);
        inorderTreeWalk(head->right);
    }
}

void freeTreeWalk(tree_t *head)
{
    if(head != NULL)
    {
        freeTreeWalk(head->left);
        freeTreeWalk(head->right);
        free(head);
    }
}

/**
 * @brief returns pointer to node containing given key, else return NULL
 * 
 * @param tree root tree
 * @param key 
 * @return tree_t* 
 */
tree_t * findNode(tree_t *tree, int key)
{
    if(tree == NULL)
    {
        return NULL;
    }

    tree_t *current = tree;

    while(current != NULL)
    {
        if(current->key == key)
        {
            return current;
        }
        else if(current->key < key)
        {
            current = current->right;
        }
        else if(current->key > key)
        {
            current = current->left;
        }
    }

    return NULL;
    
}

tree_t * insertNode(tree_t *tree, int key)
{
    if(tree == NULL)
    {
        tree = (tree_t *) malloc(sizeof(tree_t));
        tree->key = key;
        tree->left = tree->right = NULL;
    }

    if(key < tree->key)
    {
        tree->left = insertNode(tree->left, key);
    }
    else if (key > tree->key)
    {
        tree->right = insertNode(tree->right, key);
    }

    return tree;

}

tree_t *initialize(tree_t *head, int capacity)
{
    return head;
}

int main(int argc, char* argv[])
{
    tree_t *my_tree = NULL;
    tree_t *search_tree = NULL;
    my_tree = insertNode(my_tree, 4);
    insertNode(my_tree, 3);
    insertNode(my_tree, 5);

    inorderTreeWalk(my_tree);


    search_tree = findNode(my_tree, 6);
    if(search_tree)
    {
        printf("found\n");
    }

    freeTreeWalk(my_tree);


    return 0;
}
