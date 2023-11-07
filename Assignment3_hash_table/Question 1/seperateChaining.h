#include "stdio.h"
#include "stdlib.h"
#include"hashTable.h"
#include "string.h"

// Hash function to calculate the index of the key in the hash table
int hashFunction(long key, int size){
    int hash = key % size;
    return hash >= 0 ? hash : hash + size;
}

// Insert a key into the hash table using separate chaining
void hashChainInsert(hashTable *h, long key){
    int index = hashFunction(key, h->size);
    if(h->table[index]== NULL){
        // If the index is empty, create a new AVL tree and insert the key
        h->table[index] = (AVL*)malloc(sizeof(AVL));
        createAVL(h->table[index]);
        AVLinsertNode(key , h->table[index]);
    }
    else{
        // If the index is not empty, insert the key into the existing AVL tree
        AVLinsertNode(key , h->table[index]);
    }
}

// Insert an array of keys into the hash table using separate chaining
void hashChainArrayInsert(hashTable *h, long *arr, int size){
    for(int i=0;i<size;i++){
        hashChainInsert(h, arr[i]);
    }
}

// Search for a key in the hash table using separate chaining
// Returns the index of the key if found, -1 otherwise
int hashSearch(hashTable *h, long key, long **prob){
    int i = 0 ;
    **prob = 1;
    do{
        int index = hashFunction(key, h->size);
        if(h->table[index] == NULL){
            // If the index is empty, the key is not in the hash table
            return -1;
        }
        else if(FindAVL(key, h->table[index]->root,h->table[index]) != NULL ) {
            // If the key is found in the AVL tree at the index, return the index
            return index;
        }
        else{
            // If the key is not found, increment the probing count and try the next index
            **prob = **prob + 1;
            i++;
        }
    }while(i != h->size);
    // If the key is not found after probing all indices, it is not in the hash table
    return -1;
}

// Delete a key from the hash table using separate chaining
void hashDelete(hashTable *h,long key){
    long *prob = (long*)malloc(sizeof(long));
    int index = hashSearch(h, key ,&prob);
    nodeAVL * node = FindAVL(key , h->table[index]->root,h->table[index]);
    if(node  != NULL){
        // If the key is found, delete it from the AVL tree at the index
        deleteNodeAVL( h->table[index] ,node);
    } 
}

// Print the hash table as a DOT file for visualization
void hashtablePrint(hashTable *h ){
    FILE* dotFile = fopen("treeAVL.dot" , "w");
    if (!dotFile) {
        perror("Error opening DOT file");
        exit(EXIT_FAILURE);
    }
    fprintf(dotFile, "digraph BST {\n");
    for(int i = 0 ; i< h->size;i++){
        if(h->table[i] != NULL){
            if(h->table[i]->root == NULL){
                // If the index is empty, print a message indicating it is empty
                fprintf(dotFile, "index empty %d\n",i);
            }
            else{
                // If the index is not empty, generate the DOT content for the AVL tree at the index
                generateDotFileAVL(h->table[i]->root, dotFile);
                fprintf(dotFile, "\n");
            }
        }
    }
    fprintf(dotFile, "}\n");
    fclose(dotFile);
}