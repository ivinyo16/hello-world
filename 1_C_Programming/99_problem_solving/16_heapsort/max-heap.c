/**
 * @file max-heap.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
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

typedef struct data_t
{
    int key;
    int data;
}data_t;

typedef struct heap_node_t
{
    int tail;
    data_t **array;  // sorted in max-heap

}heap_node_t;


int getParent(int key)
{
    return ( (key-1)/2 );
}

int getLeftChild(int key)
{
    return ((2*key) + 1);
}

int getRightChild(int key)
{
    return ((2*key) + 2);
}

/**
 * @brief maintain max-heap by checking parent value with its child indexes and work our way down
 * 
 * @param arr 
 * @param tail 
 * @param index 
 */
void topDown_heapify(data_t **arr, int tail, int index)
{
    DEBUG_PRINT("topDown_heapify at index %d\n", index);
    int left = getLeftChild(index);
    int right = getRightChild(index);
    int largest = index; //index of largest value

    //check if left is bigger
    if( left < tail && arr[left]->key > arr[index]->key)
    {
        largest = left;
    }

    if( right < tail && arr[right]->key > arr[largest]->key)
    {
        largest = right;
    }

    
    //check if we need switching and further checking
    if(largest != index)
    {
        //swap
        data_t temp;
        
        memcpy(&temp, arr[index], sizeof(data_t));
        memcpy(arr[index], arr[largest], sizeof(data_t));
        memcpy(arr[largest], &temp, sizeof(data_t));

        topDown_heapify(arr, tail, largest);
    }
}


void bottomsUp_heapify(data_t **arr, int index)
{
    data_t temp = {0};
    DEBUG_PRINT("bottomsUp_heapify index %d\n", index);
    if(index >= 4)
    if( index == 0)
    {
        return;
    }
    int parent = getParent(index);
    DEBUG_PRINT("index: %d , parent %d\n", index, parent);

    DEBUG_PRINT("%d ---- %d\n", arr[parent]->key ,arr[index]->key);
    if( arr[parent]->key < arr[index]->key )
    {
        DEBUG_PRINT("^switch\n");
        DEBUG_PRINT("arr[parent] %p= %d   ---- arr[index]: %p= %d\n", arr[parent], arr[parent]->key, arr[index], arr[index]->key);
        memcpy(&temp, arr[index], sizeof(data_t));
        memcpy(arr[index], arr[parent], sizeof(data_t));
        memcpy(arr[parent], &temp, sizeof(data_t));
        DEBUG_PRINT("now arr[parent] %p= %d   ---- arr[index]: %p= %d\n", arr[parent], arr[parent]->key, arr[index], arr[index]->key);
        bottomsUp_heapify(arr, parent);
    }


}

void printHeap(heap_node_t *heap)
{
    for(int i = 0; i <= heap->tail ; i++ )
    {
        printf("%d, ", heap->array[i]->key);
    }
    printf("\n");
}

/**
 * @brief removes the root only
 * 
 * @param heap 
 */
void DeleteNode(heap_node_t *heap)
{
    //1. put last element contents in 0th index
    memcpy(heap->array[0], heap->array[heap->tail], sizeof(data_t));

    //2. free last index memory then decrement tail
    free(heap->array[heap->tail--]);

    topDown_heapify(heap->array, heap->tail, 0);
}

void insertNode(heap_node_t *heap, int key, int data)
{
    if(!heap)
    {
        return;
    }
    heap->tail++;
    heap->array[heap->tail] = (data_t*)malloc(sizeof(data_t));
    heap->array[heap->tail]->key = key;
    heap->array[heap->tail]->data = data;
    

    DEBUG_PRINT("\nnew_node %p = %d\n", heap->array[heap->tail], heap->array[heap->tail]->key);

    bottomsUp_heapify(heap->array, heap->tail);

    
}

heap_node_t * initializeHeap(heap_node_t *heap, int capacity)
{
    heap = (heap_node_t *)malloc(sizeof(heap_node_t));
    heap->array = (data_t**)malloc(capacity*sizeof(data_t *));
    heap->tail = -1;
    return heap;
}


int main(int argc, char* argv[])
{
    heap_node_t *heap = NULL;
    int max_capacity = 100;
    heap = initializeHeap(heap, max_capacity);
    insertNode(heap, 2, 2);
    insertNode(heap, 1, 1);
    insertNode(heap, 4, 4);
    insertNode(heap, 3, 3);
    insertNode(heap, 5, 5);
    insertNode(heap, 6, 6);

    printHeap(heap);

    DeleteNode(heap);


    printHeap(heap);



    return 0;
}
