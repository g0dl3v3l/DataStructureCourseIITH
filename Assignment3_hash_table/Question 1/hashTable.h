#include "stdio.h"
#include "stdlib.h"
#include "AVl.h"
typedef struct hashTable
{
    /* data */
    int size;
    AVL **table;

}hashTable;

void hashTableCreate(hashTable *h, int size){
    h->size = size;
    h->table = (AVL**)malloc(sizeof(AVL*)*size);
    for(int i=0;i<size;i++){
        h->table[i] = NULL;
    }
}


