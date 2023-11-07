// Include standard library for malloc function
#include "stdlib.h"
#include "stdio.h"
// Define a struct for hash node
typedef struct hashNode{
    int val; // Value of the node
    int isDeleted; // Flag to check if the node is deleted
}hashNode;

// Define a struct for hash table
typedef struct hashTable{
    int size; // Size of the hash table
    hashNode **table; // Pointer to an array of hash nodes
}hashTable;

// Function to create a hash table of given size
hashTable *createHashTable(int size){
    hashTable *h = (hashTable*)malloc(sizeof(hashTable)); // Allocate memory for hash table
    h->size = size; // Set the size of the hash table
    h->table = (hashNode**)malloc(sizeof(hashNode*)*size); // Allocate memory for the array of hash nodes
    for(int i=0;i<size;i++){
        h->table[i] = NULL; // Initialize all the hash nodes to NULL
    }
    return h; // Return the hash table
}


