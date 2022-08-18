/**
 * @file max-priority-queues.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-17
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
 * @param tail size
 * @param index index of interest
 */
void topDown_heapify(data_t **arr, int tail, int index)
{
    // DEBUG_PRINT("topDown_heapify at index %d\n", index);
    int left = getLeftChild(index);
    int right = getRightChild(index);
    int largest = index; //index of largest value

    //check if left is bigger
    if( left <= tail && arr[left]->key > arr[index]->key)
    {
        largest = left;
    }

    // DEBUG_PRINT("right compare [%d]%d _____  [%d]%d\n", right, arr[right]->key, largest, arr[largest]->key);
    if( right <= tail && arr[right]->key > arr[largest]->key)
    {
        largest = right;
    }

    
    //check if we need switching and further checking
    if(largest != index)
    {
        // DEBUG_PRINT("^switch\n");
        //swap
        data_t temp;
        
        memcpy(&temp, arr[index], sizeof(data_t));
        memcpy(arr[index], arr[largest], sizeof(data_t));
        memcpy(arr[largest], &temp, sizeof(data_t));

        topDown_heapify(arr, tail, largest);
    }
}

/**
 * @brief maintain max-heap by checking node with its parent index and work our way up
 * 
 * @param arr 
 * @param index 
 */
void bottomsUp_heapify(data_t **arr, int index)
{
    data_t temp = {0};
    // DEBUG_PRINT("bottomsUp_heapify index %d\n", index);
    if(index >= 4)
    if( index == 0)
    {
        return;
    }
    int parent = getParent(index);
    // DEBUG_PRINT("index: %d , parent %d\n", index, parent);

    // DEBUG_PRINT("%d ---- %d\n", arr[parent]->key ,arr[index]->key);
    if( arr[parent]->key < arr[index]->key )
    {
        // DEBUG_PRINT("^switch\n");
        // DEBUG_PRINT("arr[parent] %p= %d   ---- arr[index]: %p= %d\n", arr[parent], arr[parent]->key, arr[index], arr[index]->key);
        memcpy(&temp, arr[index], sizeof(data_t));
        memcpy(arr[index], arr[parent], sizeof(data_t));
        memcpy(arr[parent], &temp, sizeof(data_t));
        // DEBUG_PRINT("now arr[parent] %p= %d   ---- arr[index]: %p= %d\n", arr[parent], arr[parent]->key, arr[index], arr[index]->key);
        bottomsUp_heapify(arr, parent);
    }


}


/**
 * @brief given unordered array, set it to make it follow at least max-heap property
 * 
 * @param arr 
 * @param index 
 */
void buildMaxHeap(heap_node_t *heap)
{
    int no_leaf_end_index  = (heap->tail - 1) / 2;
    DEBUG_PRINT("no_leaf_end_index %d\n", no_leaf_end_index);
    for(int i = no_leaf_end_index ; i >= 0 ; i--)
    {
        topDown_heapify(heap->array, heap->tail, i);
    }
}

/**
 * @brief sorts the data from lowest to highest
 * 
 * @param heap 
 */
void heapSort(heap_node_t *heap)
{
    data_t temp;
    buildMaxHeap(heap);
    // return;
    int last = heap->tail;
    // DEBUG_PRINT("START NEXT PART!\n");
    for ( int i = heap->tail ; i >= 0 ; i-- )
    {
        //swap last with first
        memcpy(&temp, heap->array[0], sizeof(data_t));
        memcpy(heap->array[0], heap->array[i], sizeof(data_t));
        memcpy(heap->array[i], &temp, sizeof(data_t));
        // DEBUG_PRINT("\nheap->array[%d]: %d\n", 0, heap->array[0]->key);
        // DEBUG_PRINT("heap->array[%d]: %d\n", i, heap->array[i]->key);
        // DEBUG_PRINT("last %d\n", last-1);

        topDown_heapify(heap->array, --last, 0);
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
 * @brief returns the largest in the heap, and removes it.
 * 
 * @param heap 
 * @return data_t* this should be freed by caller
 */
data_t  * heapExtractMax(heap_node_t *heap)
{
    if(heap->tail < 0)
    {
        return NULL;
    }
    data_t * max = (data_t *) malloc(sizeof(data_t));
    //0. copy first element in our pointer
    memcpy(max, heap->array[0], sizeof(data_t));
    //1. put last element contents in 0th index
    memcpy(heap->array[0], heap->array[heap->tail], sizeof(data_t));

    //2. free last index memory then decrement tail
    free(heap->array[heap->tail--]);

    topDown_heapify(heap->array, heap->tail, 0);

    return max;

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
    

    // DEBUG_PRINT("\nnew_node %p = %d\n", heap->array[heap->tail], heap->array[heap->tail]->key);

    bottomsUp_heapify(heap->array, heap->tail);
}

void unorderedInsertNode(heap_node_t *heap, int key, int data)
{
    if(!heap)
    {
        return;
    }
    heap->tail++;
    heap->array[heap->tail] = (data_t*)malloc(sizeof(data_t));
    heap->array[heap->tail]->key = key;
    heap->array[heap->tail]->data = data;
    

    // DEBUG_PRINT("\nnew_node %p = %d\n", heap->array[heap->tail], heap->array[heap->tail]->key);

}

/**
 * @brief update the key(similar to updating priority number) of a specific heap in index 
 * new key value must be greater than current
 * 
 * @param heap 
 * @param index index of key to be replaced
 * @param key   value of new key
 */
int heapIncreaseKey(heap_node_t *heap, int index, int key)
{
    if( index > heap->tail)
    {
        DEBUG_PRINT("input index exceed size of heap\n");
        return -1;
    }
    if(heap->array[index]->key >= key)
    {
        DEBUG_PRINT("Value is greater than new key\n");
        return -1;
    }

    heap->array[index]->key = key;
    bottomsUp_heapify(heap->array, index);
    return 0;

}


data_t * HeapMaximum(heap_node_t *heap)
{
    return heap->array[0];
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
    unorderedInsertNode(heap, 2, 2);
    unorderedInsertNode(heap, 1, 1);
    unorderedInsertNode(heap, 4, 4);
    unorderedInsertNode(heap, 3, 3);
    unorderedInsertNode(heap, 5, 5);
    unorderedInsertNode(heap, 6, 6);
    unorderedInsertNode(heap, 7, 7);

    printHeap(heap);

    // heapSort(heap);
    buildMaxHeap(heap);

    data_t * max_value = HeapMaximum(heap);
    if(max_value)
    {
        printf("max value with key %d and value %d\n", max_value->key, max_value->data);
    }

    data_t * max_value_extracted  = heapExtractMax(heap);
    if(max_value_extracted)
    {
        printf("max value with key %d and value %d\n", max_value_extracted->key, max_value_extracted->data);
    }
    free(max_value_extracted);
    printHeap(heap);
    // DeleteNode(heap);
    int operation  = heapIncreaseKey(heap, 5, 9);
    if(operation < 0)
    {
        printf("error in operation]\n");
    }


    printHeap(heap);



    return 0;
}
