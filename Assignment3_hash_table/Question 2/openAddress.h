// This program implements a hash table using open addressing technique.
// It includes functions for hash function, hash insertion, hash search and hash deletion.
#include "stdio.h"
#include "stdlib.h"
#include "hashTable.h"

// hash function for open addressing
int hashFunciton(long long key, int size, int i){
    int hash = ((key % size) + i*(1 + (key % (size-1))))%size;
    return hash ;
}

// inserts a key into the hash table and returns the index where it was inserted
int hashInsert(hashTable *h, long long key,int *prob){
    int i = 0 ;
    
    do{
        int index = hashFunciton(key, h->size, i);
            *prob += 1l;
            if(h->table[index] != NULL && h->table[index]->isDeleted == 1){
                // insert the value in the deleted node
                h->table[index]->val = key;
                h->table[index]->isDeleted = 0;
                return index; 
            }else if(h->table[index] == NULL){
                //insering value in the empty node
                hashNode *newNode = (hashNode*)malloc(sizeof(hashNode));
                h->table[index] = newNode;
                h->table[index]->val = key;
                h->table[index]->isDeleted = 0;
                return index;
            }
        else{
            i++;
        }
    }while(i != h->size);
}

// inserts an array of keys into the hash table and returns the number of probes made
int hashInsertArray(hashTable *h ,long* arr, int size){
    int *prob = (int*)malloc(sizeof(int));
    *prob = 0;
    for(int i = 0; i < size; i++){
        hashInsert(h, arr[i],prob);
    }
    return *prob;
}

// searches for a key in the hash table and returns its index if found, otherwise -1
int hashSearch(hashTable *h, long long key, long **prob){
    int i = 0 ;
    **prob = 1;
    do{
        int index = hashFunciton(key, h->size, i);
     
        if(h->table[index] == NULL){
            return -1;
        }
        else if(h->table[index]->val == key && h->table[index]->isDeleted == 0){
            return index;
        }
        else{
            i++;
            **prob += 1;
        }
    }while(i != h->size);
    return -1;
}

// deletes a key from the hash table by marking its corresponding node as deleted
void hashDelete(hashTable *h, long long key){
    long *prob = (long*)malloc(sizeof(long));
    int index = hashSearch(h, key,&prob);
    if(index != -1){
        h->table[index]->isDeleted = 1;
    } 
}
