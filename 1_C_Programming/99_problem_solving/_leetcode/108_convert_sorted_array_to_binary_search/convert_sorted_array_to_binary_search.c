/**
 * @file convert_sorted_array_to_binary_search.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced 
 * binary search tree.
 * 
 * A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never 
 * differs by more than one.
 * 
 * @version 0.1
 * @date 2022-08-09
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

void inorderTreeWalk(struct TreeNode *head)
{
    if(head != NULL)
    {
        inorderTreeWalk(head->left);
        printf("%d, ", head->val);
        inorderTreeWalk(head->right);
    }
}

struct TreeNode* customCreateTree(int *nums, int low, int high, int mid)
{
    
    if(low > high)
    {
        return NULL;
    }
    DEBUG_PRINT("%d, %d, mid %d: %d\n", low, high, mid, nums[mid]);
    struct TreeNode* tree = NULL;
    tree = (struct TreeNode  *) malloc(sizeof(struct TreeNode));
    tree->val = nums[mid];
    tree->left = tree->right = NULL;



    tree->left = customCreateTree(nums, low, mid-1, ((mid-1)+(low))/2);
    tree->right = customCreateTree(nums, mid+1, high, ((high)+(mid+1))/2);
    

    return tree;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    struct TreeNode* new_tree = NULL;
    if(numsSize <= 0)
    {
        return NULL;
    }
    int low = 0;
    int high = numsSize - 1;
    int mid = (high + low) / 2;

    new_tree = customCreateTree(nums, low, high, mid);
    
    return new_tree;
}

int main(int argc, char* argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    // int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    struct TreeNode * my_tree = NULL;

    my_tree = sortedArrayToBST(arr, size);
    inorderTreeWalk(my_tree);

    return 0;
}
