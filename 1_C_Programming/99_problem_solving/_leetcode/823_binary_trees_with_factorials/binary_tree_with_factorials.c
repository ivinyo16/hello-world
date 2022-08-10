/**
 * @file binary_tree_with_factorials.c
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
 *
 *We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.
 *
 *Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.
 *
 * 
 *
 *Example 1:
 *
 *Input: arr = [2,4]
 *Output: 3
 *Explanation: We can make these trees: [2], [4], [4, 2, 2]
 *Example 2:
 *
 *Input: arr = [2,4,5,10]
 *Output: 7
 *Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 * 
 *
 *Constraints:
 *
 *1 <= arr.length <= 1000
 *2 <= arr[i] <= 109
 *All the values of arr are unique.
 * 
 * techniques used:
 *  hash mapping using double addressing
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

#define MOD (int)1000000007
// #define MOD (int)1e9+7

//table size due to constraint, to ensure all elements can be traversed, it is best for the table size to be a prime number
#define TABLE_SIZE 1009
//prime number for our second hashing method
#define PRIME 997

typedef struct s_data_node
{
    int key;
    int long long data;
}s_data_node;

//compare function for our qsort
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int firstHashFunction(int key)
{
    return key % TABLE_SIZE;
}

int secondHashFunction(int key)
{
    return 1 + (key % PRIME);
}

/**
 * @brief computes the hash_index that the input key and it's satellite data would be stored in the hashmap
 * We use a polynomial approach using PRIME number to ensure we can land at least one empty slot distributed across
 * the hash table, assuming slot is available
 *  
 *  
 * @param key 
 * @param hash_function_index 
 * @return int 
 */
int hashFunction(int key, int hash_function_index)
{
    return ( firstHashFunction(key) + (hash_function_index * secondHashFunction(key)) ) % TABLE_SIZE;;
}

/**
 * @brief check if certain entry in hash table with given hash key exists
 * 
 * @param hash_table 
 * @param key 
 * @return true 
 * @return false 
 */
bool searchTable(s_data_node **hash_table , int key)
{
    int hash_func_idx = 0;
    int hash_index;

    for( hash_func_idx = 0 ; hash_func_idx < TABLE_SIZE ; hash_func_idx++)
    {
        hash_index = hashFunction(key, hash_func_idx);
        if(hash_table[hash_index] == NULL)
        {
            return false;
        }

        if(hash_table[hash_index]->key == key)
        {
            return true;
        }

    }

    return false;

}

/**
 * @brief Set the Table Data object with the given key
 * 
 * @param hash_table 
 * @param key 
 * @param data 
 * @return int 
 */
int setTableData(s_data_node **hash_table , int key, int data)
{
    int hash_func_idx = 0;
    int hash_index;

    for( hash_func_idx = 0 ; hash_func_idx < TABLE_SIZE ; hash_func_idx++)
    {
        hash_index = hashFunction(key, hash_func_idx);
        if(hash_table[hash_index] == NULL)
        {
            return -1;
        }

        if(hash_table[hash_index]->key == key)
        {
            hash_table[hash_index]->data = data;
            return 0;
        }

    }

    return -1;

}

int long long getTableData(s_data_node **hash_table , int key)
{
    int hash_func_idx = 0;
    int hash_index;

    for( hash_func_idx = 0 ; hash_func_idx < TABLE_SIZE ; hash_func_idx++)
    {
        hash_index = hashFunction(key, hash_func_idx);
        if(hash_table[hash_index] == NULL)
        {
            return -1;
        }

        if(hash_table[hash_index]->key == key)
        {
            return hash_table[hash_index]->data;
        }

    }

    return -1;

}

void insertNode(s_data_node **hash_table, int key)
{
    int hash_function_index = 0;
    int hash_index =  hashFunction(key, hash_function_index);
    int initial_position = hash_index;
    static int test = 0;
    static int test2 = 0;

    s_data_node *item;


    while( hash_table[hash_index] != NULL )
    {
        hash_index = hashFunction(key, ++hash_function_index);
        if(hash_index == initial_position )
        {
            break;
        }
    }
    hash_table[hash_index] = (s_data_node *) malloc(sizeof(s_data_node));
    hash_table[hash_index]->key = key;
    hash_table[hash_index]->data = 1;

}

void printArray(int *arr, int arrSize)
{
    for(int i = 0; i < arrSize; i++ )
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int numFactoredBinaryTrees(int* arr, int arrSize)
{
    int *intersection_array = NULL;
    int idx;
    s_data_node *hash_table_1[TABLE_SIZE];
    int ans = 0;
    int long long placer = 0;
    
    //1. sort to increasing order
    printArray(arr, arrSize);
    qsort(arr,arrSize, sizeof(int),cmpfunc);
    printArray(arr, arrSize);

    //2. set all initially to null
    for( idx = 0 ; idx < TABLE_SIZE ; idx++ )
    {
        hash_table_1[idx] = NULL;
    }

    //3. Add each array member using array value as node's KEY. initialize "data" value to 1.
    // This holds the binary tree count for each array element
    for( idx = 0 ; idx < arrSize ; idx++ )
    {
        insertNode(hash_table_1, arr[idx]);
    }

    for(int i = 0; i < arrSize ; i++ )
    {
        for(int j = 0 ; j < i ; j++ )
        {
            //4. We entertain only if it's a factor
            if( (arr[i] % arr[j]) == 0 )
            {
                if( searchTable(hash_table_1, arr[i]/arr[j]) )
                {
                    placer = (int long long)(getTableData(hash_table_1, arr[i]) + getTableData(hash_table_1, arr[j]) * getTableData(hash_table_1, arr[i]/arr[j])) % MOD;
                    setTableData(hash_table_1, arr[i], (int) (placer % MOD)  );
                }
            }
        }
        DEBUG_PRINT("DONE for %d with count %lli\n\n", arr[i], getTableData(hash_table_1, arr[i]));
    }

    for(int i = 0 ; i < arrSize; i++ )
    {
        ans = (ans+getTableData(hash_table_1, arr[i])) % MOD;
        DEBUG_PRINT("%d\n",ans);
    }

    return ans;
}

int main(int argc, char* argv[])
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    DEBUG_PRINT("%lli\n", __LONG_LONG_MAX__);
    int size = sizeof(arr)/sizeof(arr[0]);
    int answer = numFactoredBinaryTrees( arr, size);
    printf("number of trees: %d\n", answer);


    return 0;
}
